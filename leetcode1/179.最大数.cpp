/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int left, int right) {
        string sl = to_string(left);
        string sr = to_string(right);
        return sl + sr > sr + sl;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (auto v : nums) {
            ans += to_string(v);
        }
        const char* p = ans.c_str();
        while (*p == '0') p++;
        if (*p == '\0') {
            return "0";
        }
        return p;
    }
};
// @lc code=end

