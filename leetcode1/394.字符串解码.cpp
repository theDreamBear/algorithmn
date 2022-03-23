/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
 public:
    int findEnd(const string& s, int start, int end) {
        int l = 0;
        int r = 0;
        int i = start;
        do {
            if (s[i] == '[') {
                ++i;
                ++l;
                continue;
            }
            if (s[i] == ']') {
                ++i;
                ++r;
                continue;
            }
            i++;
        } while (i <= end && l > r);
        return i;
    }

    string decodeStringHelper(const string& s, int start, int end, int times) {
        string ans;
        int i = start;
        while (i <= end) {
            if (isalpha(s[i])) {
                ans.push_back(s[i]);
                i++;
                continue;
            }
            if (!isdigit(s[i])) {
                throw logic_error("s is bad");
            }
            int val = 0;
            while (i < end && isdigit(s[i])) {
                val = val * 10 + s[i] - '0';
                i++;
            }
            if (i >= end) {
                throw logic_error("s is bad");
            }
            int r = findEnd(s, i, end);
            int l = i + 1;
            ans += decodeStringHelper(s, l, r - 2, val);
            i = r;
        }
        string temp = ans;
        for (int t = 1; t < times; t++) {
            ans += temp;
        }
        return ans;
    }

    string decodeString(string s) {
        return decodeStringHelper(s, 0, s.size() - 1, 1);
    }
};
// @lc code=end

