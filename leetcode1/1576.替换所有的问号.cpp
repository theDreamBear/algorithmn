/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
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
    string modifyString1(string s) {
        if (s.size() == 1) {
            if (s[0] == '?') {
                s[0] = 'a';
            }
            return s;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') {
                continue;
            }
            if (i == 0) {
                if (s[i + 1] != '?') {
                    s[i] = (s[i + 1] - 'a' + 1) % 26 + 'a';
                } else {
                    s[i] = 'a';
                }
                continue;
            }
            if (i == s.size() - 1) {
                s[i] = (s[i - 1] - 'a' + 1) % 26 + 'a';
                continue;
            }
            if (i > 0 && i < s.size() - 1) {
                if (s[i + 1] == '?') {
                    s[i] = (s[i - 1] - 'a' + 1) % 26 + 'a';
                } else {
                    if (s[i - 1] == s[i + 1]) {
                        s[i] = (s[i - 1] - 'a' + 1) % 26 + 'a';
                    } else {
                        int diff = abs(s[i + 1] - s[i - 1]);
                        if (diff > 1) {
                            s[i] = (s[i - 1] > s[i + 1]) ? s[i + 1] + 1 : s[i - 1] + 1;
                        } else {
                            s[i] = ((s[i - 1] > s[i + 1]) ? (s[i - 1] - 'a' + 1) : (s[i + 1] - 'a' + 1)) % 26 + 'a';
                        }
                    }
                }
            }
        }
        return s;
    }

    string modifyString(string s) {
        if (s.size() == 1) {
            if (s[0] == '?') {
                s[0] = 'a';
            }
            return s;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') {
                continue;
            }
            if (i == s.size() - 1) {
                s[i] = (s[i - 1] - 'a' + 1) % 26 + 'a';
                continue;
            }
            char left = 'a', right = 'a';
            if (s[i + 1] == '?') {
                if (i > 0) {
                    left = s[i - 1];
                }
                s[i] = (left - 'a' + 1) % 26 + 'a';
                continue;
            }
            if (i > 0) {
                left = s[i - 1];
            }
            if (i < s.size() - 1) {
                right = s[i + 1];
            }
            int diff = abs(right - left);
            if (diff > 1) {
                s[i] = (left > right) ? right + 1 : left + 1;
            } else {
                s[i] = ((left > right) ? (left - 'a' + 1) : (right - 'a' + 1)) % 26 + 'a';
            }
        }
        return s;
    }
};
// @lc code=end

