/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        auto cmp = [&](vector<int>& lhs, vector<int>& rhs) {
        if (lhs[1] != rhs[1]) {
                return lhs[1] < rhs[1];
            }
            return lhs[0] < rhs[0];
        };
        sort(points.begin(), points.end(), cmp);
        int ans = 1;
        int pos = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (pos >= points[i][0] && pos <= points[i][1]) {
                continue;
            }
            ++ans;
            pos = points[i][1];
        }
        return ans;
    }
};
// @lc code=end

