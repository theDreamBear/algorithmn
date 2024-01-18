/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1 && nums[i] != n + 1) {
                if (nums[i] == nums[nums[i] - 1]) {
                    ans.push_back(nums[i]);
                    nums[i] = n + 1;
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
                if (nums[i] == i + 1) {
                    break;
                }
                if (nums[i] == n + 1) {
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

