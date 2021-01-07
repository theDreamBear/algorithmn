/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
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
//string str = "01234567";

class Solution {
 public:
    string convertToBase7(int num) {
        string ans;
        if (num == 0) {
            return "0";
        }
        int sign = 1;
        if (num < 0) {
            sign = -1;
            num = 0 - num;
        }
        while (num) {
            char c = num % 7 + '0';
            num /= 7;
            ans.push_back(c);
        }
        reverse(ans.begin(), ans.end());
        if (sign > 0) {
            return ans;
        }
        return "-" + ans;
    }
};
// @lc code=end
