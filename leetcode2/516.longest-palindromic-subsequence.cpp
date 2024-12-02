/*
 * @lc app=leetcode.cn id=516 lang=cpp
 * @lcpr version=30204
 *
 * [516] 最长回文子序列
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
    int longestPalindromeSubseq1(string s) {
        // 区间dp
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        auto dfs = [&](auto&& dfs, int i, int j) {
            if (i > j) return 0;
            if (i == j) return 1;
            if (dp[i][j] != INT_MAX) return dp[i][j];
            if (s[i] == s[j]) {
                return dp[i][j] = dfs(dfs, i + 1, j - 1) + 2;
            }
            return dp[i][j] = max(dfs(dfs, i + 1, j), dfs(dfs, i, j - 1));
        };
        return dfs(dfs, 0, n - 1);
    }

    int longestPalindromeSubseq2(string s) {
        // 区间dp
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // 递推
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) dp[i][i] = 1;
                else {
                    if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                    else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }

    int longestPalindromeSubseq(string s) {
        // 区间dp
        int n = s.size();
        vector<int> dp(n);
        // 递推
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            int pre = 0;
            for (int j = i + 1; j < n; j++) {
                int tmp = dp[j];
                if (s[i] == s[j]) dp[j] = pre + 2;
                else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = tmp;
            }
        }
        return dp[n-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "bbbab"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

