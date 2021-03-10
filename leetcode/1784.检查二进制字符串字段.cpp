/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
    bool checkOnesSegment(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1' && s[i - 1] != '1') {
               return false;
            }
        }
        return true;
    }
};
// @lc code=end
