/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch_wrong(string s, string p) {
        int m = p.size() + 1, n = s.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n));
        dp[0][0] = true;
        for (int i = 1; i < m; i++) {
            int pi = i - 1;
            // 当前涉及二元对
            // a*
            // .*
            if (i + 1 < m && p[pi + 1] == '*') {
                // 取0次
                for (int j = 1; j < n; j++) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            for (int j = 1; j < n; j++) {
                if (dp[i][j]) {
                    continue;
                }
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

    bool isMatchHelper(vector<vector<int>>& dp, int i, int j, const string &p, const string &s) {
        if (j >= s.size()) {
            // 尾部消除
            while (i + 1 < p.size() && p[i + 1] == '*') {
                i += 2;
            }
            return i >= p.size();
        }
        if (i >= p.size()) {
            return false;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i + 1 < p.size() && p[i + 1] == '*') {
            if (p[i] != '.') {
                if (p[i] != s[j]) {
                    return isMatchHelper(dp, i + 2, j, p, s);
                }
                char ch = s[j];
                bool flag = isMatchHelper(dp, i + 2, j, p, s);
                int k = j;
                while (!flag && s[k] == ch) {
                    flag = isMatchHelper(dp, i + 2, k + 1, p, s);
                    k++;
                }
                return dp[i][j] = flag;
            }
            bool flag = isMatchHelper(dp, i + 2, j, p, s);
            int k = j;
            while (!flag && k < s.size()) {
                flag = isMatchHelper(dp, i + 2, k + 1, p, s);
                k++;
            }
            return dp[i][j] = flag;
        }
        if (p[i] == s[j] || p[i] == '.') {
            return isMatchHelper(dp, i + 1, j + 1, p, s);
        }
        return false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.size(), vector<int>(s.size(), -1));
        return isMatchHelper(dp, 0, 0, p, s);
    }
};
// @lc code=end

