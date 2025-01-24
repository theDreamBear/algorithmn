/*
 * @lc app=leetcode.cn id=2944 lang=cpp
 * @lcpr version=30204
 *
 * [2944] 购买水果需要的最少金币数
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 相复杂了
    int minimumCoins1_notgood(vector<int>& prices) {
        int n = prices.size();
        vector<array<int, 2>> f(n, {INT_MAX, INT_MAX});
        auto dfs = [&](auto&& dfs, int i, int status) {
            if (i == n - 1) {
                return status == 1 ? 0: prices[i];
            }
            auto& v = f[i][status];
            if (v != INT_MAX) return v;
            if (status) {
                v = dfs(dfs, i + 1, 0);
            }
            // 可以花钱获得
            // [i + 1, min(n - 1, i + i)]
            for (int j = i + 1; j <= min(n - 1, (i + 1) * 2 - 1); j++) {
                v = min(v, dfs(dfs, j, 1) + prices[i]);
            }
            return v;
        };
        return dfs(dfs, 0, 0);
    }

    int minimumCoins1(vector<int>& prices) {
        int n = prices.size();
        vector<int> f((n + 1) / 2, INT_MAX);
        auto dfs = [&](auto&& dfs, int i) {
            // [i + 1, 2 * i + 1]
            if (2 * i + 1 >=  n - 1) {
                return prices[i];
            }
            auto& v = f[i];
            if (v != INT_MAX) return v;
            // [i + 1, min(n - 1, i + i)]
            for (int j = i + 1; j <= 2 * i + 2; j++) {
                v = min(v, dfs(dfs, j) + prices[i]);
            }
            return v;
        };
        return dfs(dfs, 0);
    }

    // 改递推
    int minimumCoins2_notgood(vector<int>& prices) {
        int n = prices.size();
        vector<array<int, 2>> f(n, {INT_MAX, INT_MAX});
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                if (i == n - 1) {
                    f[i][j] = j == 1 ? 0: prices[i];
                    continue;
                }
                if (j == 1) {
                    f[i][j] = f[i + 1][0];
                }
                for (int k = i + 1; k <= min(n - 1, 2 * i + 1); k++) {
                    f[i][j] = min(f[i][j], f[k][1] + prices[i]);
                }
            }
        }
        return f[0][0];
    }

    int minimumCoins2(vector<int>& f) {
        int n = f.size();
        // n / 2 - 1是不变的
        for (int i = (n + 1) / 2 - 2; i >= 0; i--) {
            // [i + 1, 2 * i + 1]
            f[i] += *min_element(f.begin() + i + 1, f.begin() + 2 * i + 3);
        }
        return f[0];
    }

    class ZKW {
    public:
        vector<int> tr;
        int n = 1;

        ZKW(int sz) {
            n = 1;
            while (n < (sz + 2)) n <<= 1;
            tr.resize(n * 2, INT_MAX);
            n++;
        }

        void update(int L, int v) {
            for (tr[L += n] = v, L >>= 1; L; L >>= 1) {
                tr[L] = min(tr[L << 1], tr[L << 1 | 1]);
            }
        }

        int query(int L, int R) {
            int ans = INT_MAX;
            for (L += n - 1, R += n + 1; L ^ R ^ 1; L >>= 1, R >>= 1) {
                if (~L & 1) ans = min(ans, tr[L ^ 1]);
                if (R & 1) ans = min(ans, tr[R ^ 1]);
            }
            return ans;
        }
    };

    int minimumCoins3(vector<int>& f) {
        int n = f.size();
        ZKW zkw(n);
        for (int i = n - 1; i >= 0; i--) {
            if (2 * i + 1 < n - 1) {
                f[i] += zkw.query(i + 1, 2 * i + 2);
            }
            zkw.update(i, f[i]);
        }
        return f[0];
    }

    // 单调队列优化
    int minimumCoins(vector<int>& f) {
        int n = f.size();
        deque<int> dq;
        for (int i = n - 1; i >= 0; i--) {
            // 单调递增队列
            // 过期
            while (!dq.empty() and 2 * i + 2 < dq.front()) dq.pop_front();
            if (2 * i + 1 < n - 1) {
                f[i] += f[dq.front()];
            }
            // 入队列
            while (!dq.empty() and f[dq.back()] >= f[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return f[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [26,18,6,12,49,7,45,45]\n
// @lcpr case=end

 */

