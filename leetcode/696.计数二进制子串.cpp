/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
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
    int countBinarySubstrings(string s) {
        int sum = 0;
        int i = 0, ct_zero = 0, ct_one = 0;
        while (i < s.size()) {
            if (s[i] == '0') {
                ++ct_zero;
            } else {
                ++ct_one;
            }
            if (ct_zero == ct_one) {
                sum += ct_zero;
                for (int j = 0; j < ct_zero; ++j) {
                    string s1 = s.substr(i - j);
                    sum += countBinarySubstrings(s1);
                }
                return sum;
            }
            ++i;
        }
        return sum;
    }
};
// @lc code=end
