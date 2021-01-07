/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isAllLower(const char* str) {
        while (*str != '\0') {
            if (!islower(*str)) {
                return false;
            }
            ++str;
        }
        return true;
    }

    bool isAllUpper(const char* str) {
        while (*str != '\0') {
            if (!isupper(*str)) {
                return false;
            }
            ++str;
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        bool left = isAllLower(word.c_str() + 1);
        if (islower(word[0])) {
            return left;
        } else {
            return left || isAllUpper(word.c_str() + 1);
        }
    }
};
// @lc code=end

