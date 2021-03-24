/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    /*
        正常二维dp
    */
    int minPathSum1(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        if (grid.size() > 0) {
            for (int i = 1; i < grid[0].size(); ++i) {
                grid[0][i] += grid[0][i - 1];
            }
        }
        // 记忆化搜索
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[i].size(); ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid.back().back();
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i >= grid.size() || j >= grid[i].size()) {
            return INT_MAX;
        }
        // 备忘录
        if (grid[i][j] < 0) {
            return -grid[i][j];
        }
        if (i == grid.size() - 1 && j == grid[i].size() - 1) {
            return grid[i][j];
        }
        int left = INT_MAX;
        int right = INT_MAX;
        if (i + 1 < grid.size()) {
            left = dfs(i + 1, j, grid);
        }
        if (j + 1 < grid[i].size()) {
            right = dfs(i, j + 1, grid);
        }
        grid[i][j] = -(grid[i][j] + min(left, right));
        return -grid[i][j];
    }

    int minPathSum2(vector<vector<int>>& grid) { return dfs(0, 0, grid); }

    /*
        广度优先
    */
    int bfs(vector<vector<int>>& grid) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> minHeap;
        int m = grid.size();
        int n = grid[0].size();
        int x = 0, y = 0, v = grid[x][y];
        minHeap.push({v, 0});
        while (!minHeap.empty()) {
            auto node = minHeap.top();
            minHeap.pop();
            auto [v, x, y] = tuple<int, int, int>{node.first, node.second / n, node.second % n};
            if (grid[x][y] < 0) {
                continue;
            }
            if (x == m - 1 && y == n - 1) {
                return v;
            }
            if (x + 1 < m) {
                int nx = x + 1;
                int ny = y;
                int nv = grid[nx][ny] + v;
                minHeap.push({nv, nx * n + ny});
            }
            if (y + 1 < n) {
                int nx = x;
                int ny = y + 1;
                int nv = grid[nx][ny] + v;
                minHeap.push({nv, nx * n + ny});
            }
            grid[x][y] *= -1;
        }
        return - 1;
    }

    int minPathSum(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
// @lc code=end
