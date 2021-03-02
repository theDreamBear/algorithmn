/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
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
    vector<vector<int>> largeGroupPositions1(string s) {
        vector<vector<int>> ans;
        if (s.size() < 3) {
            return ans;
        }
        int pre = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[pre]) {
                int ct = i - pre;
                if (ct >= 3) {
                    ans.push_back({pre, i - 1});
                }
                pre = i;
            }
        }
        if (pre != s.size() - 1) {
            int ct = s.size() - pre;
            if (ct >= 3) {
                ans.push_back({pre, int(s.size() - 1)});
            }
        }
        return ans;
    }

    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        if (s.size() < 3) {
            return ans;
        }
        int pre = 0;
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == s[pre]) {
                ++i;
            }
            if (i - pre >= 3) {
                ans.push_back({pre, i - 1});
            }
            pre = i;
            ++i;
        }
        return ans;
    }
};
// @lc code=end

