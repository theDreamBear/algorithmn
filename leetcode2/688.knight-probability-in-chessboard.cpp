/*
 * @lc app=leetcode.cn id=688 lang=cpp
 * @lcpr version=30204
 *
 * [688] 骑士在棋盘上的概率
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
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        double ans = 0;
        // x, y, k
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        vector<vector<int>> dir{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
        auto dfs= [&](auto&& dfs, int x, int y, int k)->double {
            if (x < 0 || x >= n || y < 0 || y >= n) return 0;
            if (k == 0) {
                return 1;
            }
            if (dp[x][y][k] != -1) return dp[x][y][k];
            double ans = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx < 0 || nx >= n or ny < 0 || ny >= n) {
                    continue;
                }
                ans += dfs(dfs, nx, ny, k - 1);
            }
            return dp[x][y][k] = ans / 8;
        };
        return dfs(dfs, row, column, k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// 1\n0\n0\n0\n
// @lcpr case=end

 */

