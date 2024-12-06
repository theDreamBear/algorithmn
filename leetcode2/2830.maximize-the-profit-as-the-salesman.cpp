/*
 * @lc app=leetcode.cn id=2830 lang=cpp
 * @lcpr version=30204
 *
 * [2830] 销售利润最大化
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
// @lcpr-template-end
// @lc code=start
class ZKW{
public:
    int n;
    vector<int> tr;

    ZKW(int sz) {
        n = 1;
        while (n < sz + 2) n <<= 1;
        tr.resize(n << 1, 0);
        n++;
    }

    int query(int L, int R) {
        if (L > R) return 0;
        int ans = 0;
        for (L += n - 1, R += n + 1; L ^ R ^ 1; L >>= 1, R >>= 1) {
            if (~L & 1) ans = max(ans, tr[L ^ 1]);
            if (R & 1) ans = max(ans, tr[R ^ 1]);
        }
        return ans;
    }

    void update(int L, int val) {
        for (tr[L += n] = val, L >>= 1; L; L >>= 1) {
            tr[L] = max(tr[L << 1], tr[L << 1 | 1]);
        }
    }
};

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        // 区间dp问题
        ranges::sort(offers, [](auto& l, auto& r) {
            return l[0] < r[0];
        });
        vector<int> dp(n + 1);
        ZKW zkw(n + 1);
        for (int i = 0; i < offers.size(); i++) {
            // 偏大了
            int l = offers[i][0] + 1, r = offers[i][1] + 1, c = offers[i][2];
            int x = zkw.query(0, l - 1);
            if (dp[r] < x + c) {
                dp[r] = x + c;
                zkw.update(r, dp[r]);
            }
        }
        return ranges::max(dp);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[0,0,1],[0,2,2],[1,3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,0,1],[0,2,10],[1,3,2]]\n
// @lcpr case=end

 */

