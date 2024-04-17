/*
 * @lc app=leetcode.cn id=LCR 096 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 096] 交错字符串
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isInterleave1(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if (s1.empty() and s2.empty()) {
            return true;
        }
        if (s1.empty()) {
            return s2 == s3;
        }
        if (s2.empty()) {
            return s1 == s3;
        }
        // s1, s2, s3都不空
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[0][j] = s2[j - 1] == s3[j - 1] ? 1 : 0;
            if (!dp[0][j]) {
                break;
            }
        }
        for (int i = 1; i <= m; i++) {
            dp[i][0] = s1[i - 1] == s3[i - 1] ? 1 : 0;
            if (!dp[i][0]) {
                break;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = 1;
                }
                if (!dp[i][j] and dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = 1;
                }
            }
        }
        return dp.back().back();
    }

    bool isInterleave2(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if (s1.empty() and s2.empty()) {
            return true;
        }
        if (s1.empty()) {
            return s2 == s3;
        }
        if (s2.empty()) {
            return s1 == s3;
        }
        // s1, s2, s3都不空
        int m = s1.size(), n = s2.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= n and s2[j - 1] == s3[j - 1]; j++) {
            dp[j] = 1;
        }
        for (int i = 1; i <= m; i++) {
            dp[0] = dp[0] == 0 ? 0 : s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; j++) {
                dp[j] = (dp[j] and s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] and s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp.back();
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if (s1.empty() and s2.empty()) {
            return true;
        }
        if (s1.empty()) {
            return s2 == s3;
        }
        if (s2.empty()) {
            return s1 == s3;
        }
        // s1, s2, s3都不空
        int m = s1.size(), n = s2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        function<bool(int, int)> dfs = [&](int i, int j)->bool {
            if (i >= s1.size() && j >= s2.size()) {
                return true;
            }
            if (i >= s1.size()) {
                return s2.substr(j) == s3.substr(i + j);
            }
            if (j >= s2.size()) {
                return s1.substr(i) == s3.substr(i + j);
            }
            if (memo[i][j] != -1) {
                return memo[i][j];
            }
            return memo[i][j] = s1[i] == s3[i + j] and dfs(i + 1, j) ||
                                s2[j] == s3[i + j] and dfs(i, j + 1);
        };
        dfs(0, 0);
        return memo[0][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbcbcac"\n
// @lcpr case=end

// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbbaccc"\n
// @lcpr case=end

// @lcpr case=start
// ""\n""\n""\n
// @lcpr case=end

 */

