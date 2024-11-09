/*
 * @lc app=leetcode.cn id=3242 lang=cpp
 * @lcpr version=30204
 *
 * [3242] 设计相邻元素求和服务
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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class NeighborSum1 {
public:
    vector<vector<int>>& grid;
    vector<vector<int>> as{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vector<vector<int>> ds{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    map<int, pair<int, int>> mp;

    NeighborSum1(vector<vector<int>>& grid): grid(grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                mp[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        auto [x, y] = mp[value];
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int nx = x + as[k][0];
            int ny = y + as[k][1];
            if (nx >= 0 and nx < grid.size() and ny >= 0 and ny < grid[nx].size()) {
                ans += grid[nx][ny];
            }
        }
        return ans;
    }
    
    int diagonalSum(int value) {
         auto [x, y] = mp[value];
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int nx = x + ds[k][0];
            int ny = y + ds[k][1];
            if (nx >= 0 and nx < grid.size() and ny >= 0 and ny < grid[nx].size()) {
                ans += grid[nx][ny];
            }
        }
        return ans;
    }
};


class NeighborSum {
public:
    vector<vector<int>>& grid;
    vector<vector<int>> as{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vector<vector<int>> ds{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    vector<int> mp;

    NeighborSum(vector<vector<int>>& grid):grid(grid) {
        int n = grid.size();
        mp.resize(n * n);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                mp[grid[i][j]] = i * n + j;
            }
        }
    }
    
    int adjacentSum(int value) {
         auto v = mp[value];
         int x = v / grid.size();
         int y = v % grid.size();
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int nx = x + as[k][0];
            int ny = y + as[k][1];
            if (nx >= 0 and nx < grid.size() and ny >= 0 and ny < grid[nx].size()) {
                ans += grid[nx][ny];
            }
        }
        return ans;
    }
    
    int diagonalSum(int value) {
         auto v = mp[value];
         int x = v / grid.size();
         int y = v % grid.size();
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int nx = x + ds[k][0];
            int ny = y + ds[k][1];
            if (nx >= 0 and nx < grid.size() and ny >= 0 and ny < grid[nx].size()) {
                ans += grid[nx][ny];
            }
        }
        return ans;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
// @lc code=end



/*
// @lcpr case=start
// ["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"][[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]\n
// @lcpr case=end

// @lcpr case=start
// ["neighborSum", "adjacentSum", "diagonalSum"][[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]\n
// @lcpr case=end

 */

