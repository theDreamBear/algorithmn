/*
 * @lc app=leetcode.cn id=LCR 192 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 192] 把字符串转换成整数 (atoi)
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        long long value = 0;
        int sign = 1;
        const char* p = str.c_str();
        // 1. 处理前导0
        while (*p == ' ') {
            p++;
        }
        // 2. 处理+ -号
        if (*p == '+' || *p == '-') {
            if (*p == '-') {
                sign = -1;
            }
            p++;
        }
        // 去掉前导0;
        while (*p == '0') {
            p++;
        }
        // 3.处理数字
        int len = 0;
        while (*p >= '0' and *p <= '9' and len <= 11) {
            value = value * 10 + *p - '0';
            len++;
            p++;
        }
        if (sign == 1) {
            if (value >= INT_MAX) {
                return INT_MAX;
            }
            return value;
        } else {
            if (-value <= INT_MIN) {
                return INT_MIN;
            }
            return -value;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// "   -42"\n
// @lcpr case=end

// @lcpr case=start
// "4193 with words"\n
// @lcpr case=end

 */

