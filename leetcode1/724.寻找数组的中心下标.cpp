/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(int(nums.size()));
        vector<int> postfix(int(nums.size()));
        exclusive_scan(nums.begin(), nums.end(), prefix.begin(), 0);
        exclusive_scan(nums.rbegin(), nums.rend(), postfix.rbegin(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (prefix[i] == postfix[i]) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

