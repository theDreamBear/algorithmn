/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotateHelper(vector<int>& nums, int low, int high) {
        while (low < high) {
            swap(nums[low++], nums[high--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k %= sz;
        rotateHelper(nums, sz - k, sz - 1);
        rotateHelper(nums, 0, sz - k - 1);
        rotateHelper(nums, 0, sz - 1);
    }
};
// @lc code=end

