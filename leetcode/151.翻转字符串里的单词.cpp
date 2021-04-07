/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
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
    void rotate(string& s, int low, int high) {
        for (; low < high; ++low, --high) {
            swap(s[low], s[high]);
        }
    }

    string reverseWords(string s) {
        string ans;
        for (char c : s) {
            if (c == ' ') {
                // 最后可能添加多余空格
                if (!ans.empty() && ans.back() != ' ') {
                    ans.push_back(' ');
                }
            } else {
                ans.push_back(c);
            }
        }
        if (ans.back() == ' ') {
            // 删除最后的多余空格
            ans.pop_back();
        }
        int left = 0, right = 0;
        while (right < ans.size()) {
            while (right < ans.size() && ans[right] != ' ') {
                ++right;
            }
            rotate(ans, left, right - 1);
            ++right;
            left = right;
        }
        rotate(ans, 0, ans.size() - 1);
        return ans;
    }
};
// @lc code=end

