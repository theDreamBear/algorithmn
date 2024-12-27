/*
 * @lc app=leetcode.cn id=576 lang=cpp
 * @lcpr version=30204
 *
 * [576] 出界的路径数
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
int dp[100][100][100];
class Solution {
public:
    int findPaths1(int m, int n, int maxMove, int startRow, int startColumn) {
        const int mod = 1e9 + 7;
        // f(i, j, m) 代表从i, j最多经过m步能移出边界的方案数

        // f(i, j, m) = f(i - 1, j, m - 1)
        //              f(i + 1, j, m - 1)
        //              f(i, j - 1, m - 1)
        //              f(i - 1, j + 1, m - 1)
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&& dfs, int i, int j, int move) {
            if (i < 0 or i >= m or j < 0 or j >= n) {
                return 1;
            }
            if (move <= 0) {
                return 0;
            }
            auto& ans = dp[i][j][move];
            if (ans != -1) return ans;
            ans = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                ans = (ans + dfs(dfs, nx, ny, move - 1)) % mod;
            }
            return ans;
        };
        return dfs(dfs, startRow, startColumn, maxMove);
    }

    // 可以优化成滚动dp
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int mod = 1e9 + 7;
        // f(i, j, m) 代表从i, j最多经过m步能移出边界的方案数

        // f(i, j, m) = f(i - 1, j, m - 1)
        //              f(i + 1, j, m - 1)
        //              f(i, j - 1, m - 1)
        //              f(i - 1, j + 1, m - 1)
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        memset(dp, 0, sizeof dp);
        // 往下往右移动1个单位
        // dp[1][1] -> dp[m][n]
        for (int i = 0; i <= m + 1; i++) {
            for (int move = 0; move <= maxMove; move++) {
                dp[i][0][move] = dp[i][n + 1][move] = 1;
            }
        }
        for (int j = 0; j <= n + 1; j++) {
            for (int move = 0; move <= maxMove; move++) {
                dp[0][j][move] = dp[m + 1][j][move] = 1;
            }
        }
        // 错误的循环顺序, 脑子瓦特了
        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         for (int move = 1; move <= maxMove; move++) {
        //             for (int k = 0; k < 4; k++) {
        //                 int nx = i + dx[k];
        //                 int ny = j + dy[k];
        //                 dp[i][j][move] = (dp[i][j][move] + dp[nx][ny][move - 1]) % mod;
        //             }
        //         }
        //     }
        // }
        // 正确的顺序
        for (int move = 1; move <= maxMove; move++) {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    for (int k = 0; k < 4; k++) {
                        int nx         = i + dx[k];
                        int ny         = j + dy[k];
                        dp[i][j][move] = (dp[i][j][move] + dp[nx][ny][move - 1]) % mod;
                    }
                }
            }
        }
        return dp[startRow + 1][startColumn + 1][maxMove];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n2\n2\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// 1\n3\n3\n0\n1\n
// @lcpr case=end

 */

