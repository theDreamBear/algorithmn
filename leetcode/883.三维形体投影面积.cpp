/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int projectionArea1(vector<vector<int>>& grid) {
        // unordered_map<int, int> yz;
        // unordered_map<int, int> xz;

        vector<int> yz(51);
        vector<int> xz(51);

        int ans = 0;
        for (int x = 0; x < grid.size(); ++x) {
            xz[x] = 0;
            for (int y = 0; y < grid[x].size(); ++y) {
                int z = grid[x][y];
                if (z > 0) {
                    ++ans;
                }
                if (z > xz[x]) {
                    xz[x] = z;
                }
                if (z > yz[y]) {
                    yz[y] = z;
                }
            }
        }
        for (auto& kv : yz) {
            ans += kv;
        }
        for (auto& kv : xz) {
            ans += kv;
        }
        return ans;
    }

    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        for (int x = 0; x < grid.size(); ++x) {
            int max_x = 0, max_y = 0;
            for (int y = 0; y < grid[x].size(); ++y) {
                if (grid[x][y] > 0) {
                    ++ans;
                }
                max_x = max(max_x, grid[x][y]);
                // grid[y][x])这个地方有点意思；
                max_y = max(max_y, grid[y][x]);
            }
            ans += (max_x + max_y);
        }
        return ans;
    }
};
// @lc code=end

