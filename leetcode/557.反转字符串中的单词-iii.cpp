/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
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
    void rot(string& s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        int cur = 0;
        do {
            while (cur < s.size() && isspace(s[cur])) {
                ++cur;
            }
            int end = cur;
            while (end < s.size() && !isspace(s[end])) {
                ++end;
            }
            rot(s, cur, end - 1);
            cur = end + 1;
        } while(cur < s.size());
        return s;
    }
};
// @lc code=end

