/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 * @lcpr version=30204
 *
 * [1312] 让字符串成为回文串的最少插入次数
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
    int minInsertions1(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        auto dfs = [&](auto&& dfs, int l, int r) {
            if (l >= r) return 0;
            if (dp[l][r] != INT_MIN) return dp[l][r];
            if (s[l] == s[r]) return dp[l][r] = dfs(dfs, l + 1, r - 1);
            return dp[l][r] = 1 + min(dfs(dfs, l + 1, r), dfs(dfs, l, r - 1));
        };
        return dfs(dfs, 0, n - 1);
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "zzazz"\n
// @lcpr case=end

// @lcpr case=start
// "mbadm"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */

