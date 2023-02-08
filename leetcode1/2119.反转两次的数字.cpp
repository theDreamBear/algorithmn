/*
 * @lc app=leetcode.cn id=2119 lang=cpp
 *
 * [2119] 反转两次的数字
 */

// @lc code=start
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num >= 0 && num <= 9) {
            return true;
        }
        string s = to_string(num);
        if (s.back() == '0') {
            return false;
        }
        return true;
    }
};
// @lc code=end

