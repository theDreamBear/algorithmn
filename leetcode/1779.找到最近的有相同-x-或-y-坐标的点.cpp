/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
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
    /*
        垃圾题, 题干简直垃圾

    */
    int nearestValidPoint1(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int minDis = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] == x || points[i][1] == y) {
                int d = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (d < minDis) {
                    ans = i;
                    minDis = d;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

