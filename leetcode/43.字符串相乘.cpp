/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
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
    string multiply1(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i) {
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; --j) {
                int val = (num2[j] - '0') * (num1[i] - '0') + (ans[i + j + 1] - '0') + carry;
                ans[i + j + 1] = val % 10 + '0';
                carry = val / 10;
            }
            ans[i] += carry;
        }
        if (ans[0] == '0') {
            return ans.c_str() + 1;
        }
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int sz = num1.size() + num2.size();
        vector<int> ans(sz);
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                ans[i + j + 1] += ((num1[i] - '0') * (num2[j] - '0'));
            }
        }
        for (int pos = sz - 1; pos > 0; --pos) {
            int val = ans[pos];
            ans[pos] = val % 10;
            ans[pos - 1] += (val / 10);
        }
        string temp(sz, '0');
        for (int start = sz - 1; start >= 0; --start) {
            temp[start] += ans[start];
        }
        if (temp[0] == '0') {
            return temp.substr(1);
        }
        return temp;
    }
};
// @lc code=end

