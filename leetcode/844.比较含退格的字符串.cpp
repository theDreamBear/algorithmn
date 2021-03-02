/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
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
    string getString(const string& str) {
        string ans;
        for (auto c : str) {
            if (c != '#') {
                ans.push_back(c);
            } else {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
    bool backspaceCompare1(string S, string T) {
        return getString(S) == getString(T);
    }

     bool backspaceCompare(string S, string T) {
        int i = 0, j = 0;
        return false;
    }
};
// @lc code=end

