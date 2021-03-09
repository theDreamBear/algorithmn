/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 *
 * [1266] 访问所有点的最小时间
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
#include <numeric>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); ++i) {
            ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }
        return ans;
    }
};
// @lc code=end

