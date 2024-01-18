/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        const char* p = s.c_str();
        // 前导空格
        while (*p == ' ') p++;
        if (*p == '\0') {
            return 0;
        }
        // 符号
        if (*p == '-' || *p == '+') {
            if (*p == '-') {
                sign = -1;
            }
            p++;
        }
        if (*p == '\0') {
            return 0;
        }
        // 前导0
        while (*p == '0') p++;
        if (*p == '\0') {
            return 0;
        }
        // 数字
        long long ans = 0;
        while (ans <= (long long)INT32_MAX + 1 && *p >= '0' && *p <= '9') {
            ans = ans * 10 + (*p - '0');
            p++;
        }
        ans *= sign;
        if (ans <= INT32_MIN) {
            return INT32_MIN;
        }
        if (ans >= INT32_MAX) {
            return INT32_MAX;
        }
        return ans;
    }
};

// @lc code=end

