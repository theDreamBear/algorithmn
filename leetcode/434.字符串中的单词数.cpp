/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
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
    int countSegments(string s) {
        const char* ptr = s.c_str();
        int ans = 0;
        while (*ptr != 0) {
            while (*ptr != 0 && isspace(*ptr)) {
                ++ptr;
            }
            if (*ptr == 0) {
                break;
            }
            ++ans;
            while (*ptr != 0 && !isspace(*ptr)) {
                ++ptr;
            }
            if (*ptr == 0) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

