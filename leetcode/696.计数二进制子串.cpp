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
    /*
    两根指针
    */
    int countBinarySubstrings1(string s) {
        if (s.size() <= 1) {
            return 0;
        }
        int sum = 0;
        int i = 0, j = 1, ct_zero = 0, ct_one = 0;
        if (s[0] == '0') {
            ct_zero++;
        } else {
            ct_one++;
        }
        while (j < s.size()) {
            while (j < s.size() && s[j] == s[i]) {
                if (s[j] == '0') {
                    ++ct_zero;
                } else {
                    ++ct_one;
                }
                ++j;
            }
            while (j < s.size() && s[j] != s[i]) {
                if (s[j] == '0') {
                    ++ct_zero;
                } else {
                    ++ct_one;
                }
                ++j;
            }
            sum += min(ct_zero, ct_one);
            if (s[i] == '0') {
                i += ct_zero;
                ct_zero = 0;
            } else {
                i += ct_one;
                ct_one = 0;
            }
        }
        sum += min(ct_zero, ct_one);
        return sum;
    }

    int countBinarySubstrings2(string s) {
        vector<int> nums;
        int i = 0;
        while (i < s.size()) {
            int count = 0;
            char c = s[i];
            while (i < s.size() && s[i] == c) {
                ++count;
                ++i;
            }
            nums.push_back(count);
        }
        int sum = 0;
        for (int m = 1; m < nums.size(); ++m) {
            sum += min(nums[m - 1], nums[m]);
        }
        return sum;
    }

    /*
        计算每一段的长度和上一段的长度作比较
    */
    int countBinarySubstrings(string s) {
        int i = 0, pre = 0, cur = 0;
        int sum = 0;
        while (i < s.size()) {
            char c = s[i];
            cur = 0;
            while (i < s.size() && s[i] == c) {
                ++i;
                ++cur;
            }
            sum += min(pre, cur);
            pre = cur;
        }
        return sum;
    }
};
// @lc code=end
