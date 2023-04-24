/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size() + 1, n = s.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n));
        dp[0][0] = true;
        for (int i = 1; i < m; i++) {
            int pi = i - 1;
            for (int j = 1; j < n; j++) {
                int sj = j - 1;
                if (p[pi] == s[sj] || p[pi] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (i > 1 && p[pi] == '*') {
                    if (p[pi - 1] == s[sj] || p[pi - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

