/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
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
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x = coordinates[1][0] - coordinates[0][0];
        int y = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            int nx = coordinates[i][0] - coordinates[0][0];
            int ny = coordinates[i][1] - coordinates[0][1];
            if (x * ny != y * nx) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

