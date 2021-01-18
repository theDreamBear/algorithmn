/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
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
    void rot(string&str, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(str[i], str[j]);
        }
    }


    string reverseStr(string s, int k) {
        int pos = 0;
        int sz = s.size();
        while (pos + 2 * k < sz) {
            rot(s, pos, pos + k - 1);
            pos += 2* k;
        }
        if (pos + k < sz) {
            rot(s, pos, pos + k - 1);
        } else {
            rot(s, pos, sz - 1);
        }
        return s;
    }
};
// @lc code=end

