/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
 private:
    vector<int> data;
    int max_len;
 public:
    void backtrack(int len, int last, int pos) {
        if (pos >= data.size()) {
            if (len > max_len) {
                max_len = len;
            }
            return;
        }
        // 选
        if (len == 0 || last < data[pos]) {
            backtrack(len + 1, data[pos], pos + 1);
        }
        // 不选
        backtrack(len, last, pos + 1);
    }

    int lengthOfLIS(vector<int>& nums) {
        data = nums;
        max_len = 0;
        backtrack(0, 0, 0);
        return max_len;
    }
};
// @lc code=end

