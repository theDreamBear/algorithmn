/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
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
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x0 = points[0][0] - points[1][0];
        int y0 = points[0][1] - points[1][1];

        int x1 = points[2][0] - points[1][0];
        int y1 = points[2][1] - points[1][1];

        return x0 * y1 != x1 * y0;
    }
};
// @lc code=end

