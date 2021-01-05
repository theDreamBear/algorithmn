/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
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
     一般方法
    */
    int islandPerimeter_ordinary(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    // 左
                    if (j == 0 || (j - 1 >= 0 && grid[i][j - 1] == 0)) {
                        ++ans;
                    }
                    // 右
                    if (j == grid[i].size() - 1 ||
                        (j + 1 < grid[i].size() && grid[i][j + 1] == 0)) {
                        ++ans;
                    }
                    // 上
                    if (i == 0 || (i - 1 >= 0 && grid[i - 1][j] == 0)) {
                        ++ans;
                    }
                    // 下
                    if (i == grid.size() - 1 ||
                        (i + 1 < grid.size() && grid[i + 1][j] == 0)) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }

    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0) {
            return 1;
        }
        if (grid[i][j] == 2) {
            return 0;
        }
        grid[i][j] = 2;
        int res = 0;
        for (int k = 0; k < 4; ++k) {
            int xx = i + dx[k];
            int yy = j + dy[k];
            res += dfs(grid, xx, yy);
        }
        return res;
    }

    /*
        dfs 方法
    */
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    ans += dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
