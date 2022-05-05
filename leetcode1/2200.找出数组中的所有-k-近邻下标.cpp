/*
 * @lc app=leetcode.cn id=2200 lang=cpp
 *
 * [2200] 找出数组中的所有 K 近邻下标
 */

// @lc code=start
class Solution {
   public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        unordered_map<int, int> cnt;
        for (int i = 0; i < k && i < nums.size(); i++) {
            cnt[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                --cnt[nums[i - k - 1]];
            }
            if (i + k < nums.size()) {
                ++cnt[nums[i + k]];
            }
            if (cnt[key] > 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

