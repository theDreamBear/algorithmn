/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */
#include <ranges.h>
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
    int surfaceArea(vector<vector<int>>& grid) {
        int ct = 0;
        int faced = 0;
        int del = 0;
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid[x].size(); ++y) {
                if (grid[x][y] > 0) {
                    ct += grid[x][y];
                    faced += (grid[x][y] - 1);
                    // 右
                    if (x + 1 < grid.size()) {
                        del = min(grid[x][y], grid[x + 1][y]);
                        faced += del;
                    }
                    // 下
                    if (y + 1 < grid[x].size()) {
                        del = min(grid[x][y], grid[x][y + 1]);
                        faced += del;
                    }
                }
            }
        }
        return 6 * ct - 2 * faced;
    }
};
// @lc code=end
