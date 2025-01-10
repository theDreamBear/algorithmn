/*
 * @lc app=leetcode.cn id=812 lang=cpp
 * @lcpr version=30204
 *
 * [812] 最大三角形面积
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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        ranges::sort(points);
        double ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    double area = 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[0,1],[1,0],[0,2],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0],[0,0],[0,1]]\n
// @lcpr case=end

 */

