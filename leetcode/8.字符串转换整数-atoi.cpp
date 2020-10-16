/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
    const char* trimLeft(const char* str) {
        while ('\0' != *str && ' ' == *str) {
            ++str;
        }
        return str;
    }

    int getSigned(const char* str) {
        if ('\0' != *str && '-' == *str) {
            ++str;
            return -1;
        }
        return 1;
    }

    constexpr static char* t = "";

    const char* skipSigned(const char* str) {
        if ('\0' != *str) {
            if ('+' == *str || '-' == *str) {
                return ++str;
            } else if ('0' > *str || '9' < *str) {
                return t;
            }
        }
        return str;
    }
        
    

    int myAtoi(string s) {
        const char* str = trimLeft(s.c_str());
        if ('\0' == *str) {
            return 0;
        }
        int sign = getSigned(str);
        str = skipSigned(str);
        if ('\0' == *str) {
            return 0;
        }
        long long num = 0;
        while ('\0' != *str && '0' <= *str && '9' >= *str) {
            num = 10 * num + *str - '0';
            if (sign  == 1) {
                if (num >= INT32_MAX) {
                    return INT32_MAX;
                }
            } else {
                if (num * -1 <= INT32_MIN) {
                    return INT32_MIN;
                }
            }
            ++str;
        }
        return num * sign;
    }
};
// @lc code=end

int main() {
    string s = "42";
    cout << Solution{}.myAtoi(s);
}