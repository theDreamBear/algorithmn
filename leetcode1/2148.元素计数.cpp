/*
 * @lc app=leetcode.cn id=2148 lang=cpp
 *
 * [2148] 元素计数
 */

// @lc code=start
class Solution {
public:
    int countElements(vector<int>& nums) {
        int ans = nums.size();
        auto [mm, ma] = minmax_element(nums.begin(), nums.end());
        for (auto v : nums) {
            if (v == *mm || v == *ma) {
                --ans;
            }
        }
        return ans;
    }
};
// @lc code=end

