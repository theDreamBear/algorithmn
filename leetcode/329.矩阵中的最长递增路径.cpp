/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    int dfs(int x, int y, vector<vector<int>>& dp, const vector<vector<int>>& matrix) {
        if (dp[x][y]) {
            return dp[x][y];
        }
        int res = 1;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= dp.size() || ny < 0 || ny >= dp[nx].size() || matrix[x][y] >= matrix[nx][ny]) {
                continue;
            }
            int now = dfs(nx, ny, dp, matrix);
            res = max(res, now + 1);
        }
        return dp[x][y] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (!dp[i][j]) {
                    res = max(res, dfs(i, j, dp, matrix));
                }
            }
        }
        return res;
    }
};
// @lc code=end

