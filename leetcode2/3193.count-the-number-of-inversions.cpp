/*
 * @lc app=leetcode.cn id=3193 lang=cpp
 * @lcpr version=30204
 *
 * [3193] 统计逆序对的数目
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
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
int f[310][500];
class Solution {
  public:
    int numberOfPermutations1(int n, vector<vector<int>>& requirements) {
        // 还是不会气死人了
        // 如果要记录前i个填了啥, 这个一定会超时的, 怎么避开这个陷阱呢?
        // 每个位置枚举可以生成的最多逆序对, 最多少i个
        // 好像会了
        memset(f, -1, sizeof f);
        vector<int> req(n, -1);
        req[0] = 0;
        for (auto& vec : requirements) {
            req[vec[0]] = vec[1];
        }
        const int mod = 1e9 + 7;
        if (req[0])
            return 0;
        auto dfs = [&](auto& dfs, int i, int left) -> int {
            if (i == 0) {
                return left == 0;
            }
            auto& ans = f[i][left];
            if (ans != -1)
                return ans;
            ans = 0;
            // 当前状态是否是对的
            if (req[i] != -1 and left != req[i]) {
                return 0;
            }
            for (int k = 0; k <= min(i, left); k++) {
                ans = (ans + dfs(dfs, i - 1, left - k)) % mod;
            }
            return ans;
        };
        return dfs(dfs, n - 1, req[n - 1]);
    }

    int numberOfPermutations2(int n, vector<vector<int>>& requirements) {
        // 还是不会气死人了
        // 如果要记录前i个填了啥, 这个一定会超时的, 怎么避开这个陷阱呢?
        // 每个位置枚举可以生成的最多逆序对, 最多少i个
        // 好像会了
        memset(f, 0, sizeof f);
        vector<int> req(n, -1);
        req[0] = 0;
        for (auto& vec : requirements) {
            req[vec[0]] = vec[1];
        }
        const int mod = 1e9 + 7;
        if (req[0])
            return 0;
        f[0][0] = 1;
        for (int i = 1; i < n; i++) {
            vector<int> suf(402);
            for (int left = 400; left >= 0; left--) {
                suf[left] = (suf[left + 1] + f[i - 1][left]) % mod;
            }
            // f[i][j] = sum(f[i - 1][left - m])
            for (int left = 0; left <= 400; left++) {
                if (req[i] != -1 and req[i] != left) {
                    f[i][left] = 0;
                } else {
                    f[i][left] = (suf[left - min(i, left)] - suf[left + 1] + mod) % mod;
                }
            }
        }
        return  f[n - 1][req[n - 1]];
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        // 还是不会气死人了
        // 如果要记录前i个填了啥, 这个一定会超时的, 怎么避开这个陷阱呢?
        // 每个位置枚举可以生成的最多逆序对, 最多少i个
        // 好像会了
        int dp[500];
        memset(dp, 0, sizeof dp);
        vector<int> req(n, -1);
        req[0] = 0;
        for (auto& vec : requirements) {
            req[vec[0]] = vec[1];
        }
        const int mod = 1e9 + 7;
        if (req[0])
            return 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            vector<int> suf(402);
            for (int left = 400; left >= 0; left--) {
                suf[left] = (suf[left + 1] + dp[left]) % mod;
            }
            for (int left = 0; left <= 400; left++) {
                if (req[i] != -1 and req[i] != left) {
                    dp[left] = 0;
                } else {
                    dp[left] = (suf[left - min(i, left)] - suf[left + 1] + mod) % mod;
                }
            }
        }
        return  dp[req[n - 1]];
    }
};

class Solution1 {
    const int MOD = 1'000'000'007;
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n, -1);
        req[0] = 0;
        for (auto& p : requirements) {
            req[p[0]] = p[1];
        }
        if (req[0]) {
            return 0;
        }
        int m = ranges::max(req);
        vector<vector<int>> memo(n, vector<int>(m + 1, -1)); // -1 表示没有计算过
        auto dfs = [&](auto&& dfs, int i, int j) -> int {
            if (i == 0) {
                return 1;
            }
            int& res = memo[i][j]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            res = 0;
            // 判断是否能够转移到下一个状态
            if (int r = req[i - 1]; r >= 0) {
                if (j >= r && j - i <= r) {
                    res = dfs(dfs, i - 1, r);
                }
            } else {
                for (int k = 0; k <= min(i, j); k++) {
                    res = (res + dfs(dfs, i - 1, j - k)) % MOD;
                }
            }
            return res;
        };
        return dfs(dfs, n - 1, req[n - 1]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n[[2,2],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[2,2],[1,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0],[1,0]]\n
// @lcpr case=end

 */
