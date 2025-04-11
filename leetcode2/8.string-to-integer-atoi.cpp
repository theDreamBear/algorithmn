/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=30204
 *
 * [8] 字符串转换整数 (atoi)
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        const char* p = s.c_str();
        if (*p == '\0') return 0;
        while (*p == ' ') p++;
        int sign = 1;
        if (*p == '+' or *p == '-') {
            if (*p == '-') sign = -1;
            p++;
        }
        const int preLimts = INT_MAX / 10;
        int value = 0;
        auto isOver = [&](int val) -> bool {
            if (value > preLimts or (value == preLimts and sign == 1 and val >= 7) or (value == preLimts and sign == -1 and val >= 8)) {
                if (sign == 1) {
                    value = INT_MAX;
                } else {
                    value = INT_MIN;
                }
                return true;
            }
            value = value * 10 + val;
            return false;
        };
        while (*p != '\0') {
            int val = *p - '0';
            if (val < 0 or val > 9) {
                break;
            }
            auto b= isOver(val);
            if (b) {
                return value;
            }
            p++;
        }
        return sign * value;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// " -042"\n
// @lcpr case=end

// @lcpr case=start
// "1337c0d3"\n
// @lcpr case=end

// @lcpr case=start
// "0-1"\n
// @lcpr case=end

// @lcpr case=start
// "words and 987"\n
// @lcpr case=end

 */

