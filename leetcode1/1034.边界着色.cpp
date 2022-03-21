/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边界着色
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
    constexpr static int BASE = 1005;

    // 边界考虑简单了
    // 边界考虑不清楚, 就很容易错
    // 复杂了
    void colorOne(vector<vector<int>> &grid, vector<vector<int>>& visited, int row, int col, int source, int color, queue<int>& q) {
        // 是否访问过
        if (visited[row][col]) {
            return;
        }
        // 设置为访问过
        visited[row][col] = 1;
        bool isBoundary = false;
        for (int k = 0; k < size(dx); k++) {
            int nx = row + dx[k];
            int ny = col + dy[k];
            if (nx < 0 || ny < 0 || nx >= grid.size() || ny>= grid[nx].size() || (grid[nx][ny] != source && grid[nx][ny] != -color)) {
                isBoundary = 1;
                continue;
            }
            if (!visited[nx][ny]) {
                int v = nx * BASE + ny;
                q.push(v);
            }
        }
        if (isBoundary) {
            grid[row][col] = -color;
        }
    }
    // 复杂了
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
        if (grid[row][col] == color) {
            return grid;
        }
        vector<vector<int>> visited(grid.size(), vector<int>(grid[row].size()));
        queue<int> q;
        int source = grid[row][col];
        colorOne(grid, visited, row, col, source, color, q);
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            int x = v / BASE;
            int y = v % BASE;
            colorOne(grid, visited, x, y, source, color, q);
        }
        for (auto & vec : grid) {
            for(auto& v : vec) {
                if (v == -color) {
                    v = color;
                }
            }
        }
        return grid;
    }
};
// @lc code=end

