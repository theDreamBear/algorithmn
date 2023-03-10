/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea_violate(vector<int>& height) {
        // 最暴力的， 便利所有的， 求最大值
        int ans = 0;
        for (int left = 0; left < height.size(); left++) {
            for (int right = left + 1; right < height.size(); right++) {
                int h = min(height[left], height[right]);
                ans = max(ans, (right - left) * h);
            }
        }
        return ans;
    }

    int maxArea(vector<int>& height) {
        // 优化
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int h = min(height[left], height[right]);
            ans = max(ans, (right - left) * h);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};
// @lc code=end

