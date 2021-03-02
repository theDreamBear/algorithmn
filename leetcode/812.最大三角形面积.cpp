/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
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

using namespace std;

// @lc code=start
class Solution {
public:
    double get_area(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
        double l1 = sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
        double l2 = sqrt(pow(a.first - c.first, 2) + pow(a.second - c.second, 2));
        double l3 = sqrt(pow(c.first - b.first, 2) + pow(c.second - b.second, 2));
        double d = (l1 + l2 + l3) / 2;
        return sqrt(d * (d - l1) * (d - l2) * (d - l3));
    }

    /*
        鞋带公式
    */
    double get_area_shoecale(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
        double val = a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first;
        return 0.5 * abs(val);
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0;
        for (int i = 2; i < points.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                for (int k = 0; k < j; ++k) {
                    double ar = get_area_shoecale({points[i][0], points[i][1]}, {points[j][0], points[j][1]}, {points[k][0], points[k][1]});
                    if (ar > max_area) {
                        max_area = ar;
                    }
                }
            }
        }
        return max_area;
    }
};
// @lc code=end

