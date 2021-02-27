/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int ct = 1;
        int left = 100;
        for (auto c : s) {
            if (left < widths[c - 'a']) {
                left = 100;
                ++ct;
            }
            left -=  widths[c - 'a'];
        }
       return {ct, 100 - left};
    }
};
// @lc code=end

