/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
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
    bool partCompare(const string& left, const string& right, int i, int j) {
        for (; i < left.size() && j < right.size(); ++i, ++j) {
            if (left[i] != right[j]) {
                return false;
            }
        }
        return i == left.size() && j == right.size();
    }

    vector<vector<int>> dp;
    bool dfs(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
        if (i == s1.size() && j == s2.size()) {
            dp[i][j] == 1;
            return true;
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        if(i == s1.size()) {
            return dp[i][j] = partCompare(s2, s3, j, k);
        }
        if (j == s2.size()) {
            return dp[i][j] = partCompare(s1, s3, i, k);
        }
        if (s1[i] == s3[k] && dfs(s1, s2, s3, i + 1, j, k + 1)) {
            dp[i][j] = 1;
            return true;
        }
        if (s2[j] == s3[k] && dfs(s1, s2, s3, i, j + 1, k + 1)) {
            dp[i][j] = 1;
            return true;
        }
        dp[i][j] = 0;
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        // 边界
        // 长度必须相等
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, INT_MAX));

        return dfs(s1, s2, s3, 0, 0, 0);
    }
};
// @lc code=end

