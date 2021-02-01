/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */
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
    string toLowerCase(string str) {
        for (auto& c : str) {
            if (c >= 'A' && c <= 'Z') {
                c |= 0x20;
            }
        }
        return str;
    }
};
// @lc code=end
