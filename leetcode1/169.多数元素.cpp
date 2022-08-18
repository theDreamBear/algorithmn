/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }
        int ans = 0;
        int ct = 0;
        for (int i = 0; i < nums.size(); i++) {
           if (ct == 0) {
               ans = nums[i];
               ++ct;
           } else {
               if (ans == nums[i]) {
                   ++ct;
                   continue;
               }
               --ct;
           }
        }
        return ans;
    }
};
// @lc code=end

