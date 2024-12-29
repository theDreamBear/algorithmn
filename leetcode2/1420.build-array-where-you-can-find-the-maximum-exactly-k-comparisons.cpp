/*
 * @lc app=leetcode.cn id=1420 lang=cpp
 * @lcpr version=30204
 *
 * [1420] 生成数组
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
long long dp[100][200][100];
class Solution {
public:
    int numOfArrays1(int n, int m, int k) {
        // 
        const int mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&&dfs, int i, int mx, int left)->int {
            if (i >= n) return left == 0;
            auto& ans = dp[i][mx][left];
            if (ans != -1) return ans;
            ans = 0;
            for (int j = 1; j <= mx; j++) {
                ans = (ans + dfs(dfs, i + 1, mx, left)) % mod;
            }
            if (left > 0) {
                for (int j = mx + 1; j <= m; j++) {
                    ans = (ans + dfs(dfs, i + 1, j, left - 1)) % mod;
                }
            }
            return ans;
        };
        return dfs(dfs, 0, 0, k);
    }

    int numOfArrays2(int n, int m, int k) {
        // 
        const int mod = 1e9 + 7;
        //long long f[200][200];
        memset(dp, 0, sizeof dp);
        for (int mx = 1; mx <= m; mx++) {
            dp[n][mx][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            vector<long long> cols(k + 1);
            for (int mx = m; mx >= 0; mx--) {
                for (int left = 0; left <= k; left++) {
                    dp[i][mx][left] = ( dp[i + 1][mx][left] * mx) % mod;
                    if (left > 0) {
                        dp[i][mx][left] = (dp[i][mx][left] + cols[left - 1]) % mod;
                    }
                }
                for (int left = 0; left <= k; left++) {
                    cols[left] = (cols[left] + dp[i + 1][mx][left]) % mod;
                }
            }
        }
        return dp[0][0][k];
    }

    int numOfArrays(int n, int m, int k) {
        // 
        const int mod = 1e9 + 7;
        long long f[200][200];
        memset(f, 0, sizeof f);
        for (int mx = 1; mx <= m; mx++) {
            f[mx][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            vector<long long> cols(k + 1, 0);
            for (int mx = m; mx >= 0; mx--) {
                vector<int> olds(k + 1);
                for (int left = 0; left <= k; left++) {
                    olds[left] = f[mx][left];
                    f[mx][left] = (f[mx][left] * mx) % mod;
                    if (left > 0) {
                        f[mx][left] = (f[mx][left] + cols[left - 1]) % mod;
                    }
                }
                for (int left = 1; left <= k; left++) {
                    cols[left - 1] = (cols[left - 1] + olds[left - 1]) % mod;
                }
            }
        }
        return f[0][k];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 5\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 9\n1\n1\n
// @lcpr case=end

 */

