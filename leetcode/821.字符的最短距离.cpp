/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
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
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        vector<int> temp;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                temp.push_back(i);
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                ans.push_back(0);
            } else {
                auto pos = upper_bound(temp.begin(), temp.end(), i);
                if (pos == temp.end()) {
                    int l = temp[temp.size() - 1];
                    ans.push_back(abs(l - i));
                } else if (pos == temp.begin()) {
                    ans.push_back(abs(*pos - i));
                } else {
                    ans.push_back(min(abs(*(pos - 1) - i), (*pos - i)));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

