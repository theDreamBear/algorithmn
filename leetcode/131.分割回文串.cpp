/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <ranges.h>
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
    bool isValid(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    void backtracking(vector<vector<string>>& ans, vector<string>& temp, const string& s, int pos) {
        if (pos == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = pos; i < s.size(); ++i) {
            if (isValid(s, pos, i)) {
                temp.push_back(s.substr(pos, i - pos + 1));
                backtracking(ans, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition1(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtracking(ans, temp, s, 0);
        return ans;
    }

    void backtracking1(vector<vector<string>>& ans, vector<string>& temp, const string& s, int pos, const vector<vector<bool>>& dp) {
         if (pos == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = pos; i < s.size(); ++i) {
            if (dp[pos][i]) {
                temp.push_back(s.substr(pos, i - pos + 1));
                backtracking(ans, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }

    /*
        观察方法1 发现isValid(s, pos, i) 是会重复的，需要提前算出来， 或者计算后存储下来
    */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        // i == j 默认为true
        // j > i  默认为true;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = s[j] == s[i] && dp[j + 1][i - 1];
            }
        }
        backtracking1(ans, temp, s, 0, dp);
        return ans;
    }
};
// @lc code=end
