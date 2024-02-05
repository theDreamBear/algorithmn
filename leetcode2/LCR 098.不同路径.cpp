/*
 * @lc app=leetcode.cn id=LCR 098 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 098] 不同路径
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
#include <numeric>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int dfs(int x, int y, int m, int n, unordered_map<int, int>& memo) {
        if (x >= m || y >= n) {
            return 0;
        }
        if (x + 1 == m && y + 1 == n) {
            return 1;
        }
        int k = x * 1000 + y;
        if (memo.count(k)) {
            return memo[k];
        }
        return memo[k] =  dfs(x + 1, y, m, n, memo) + dfs(x, y + 1, m, n, memo);
    }

    int uniquePaths_dfs(int m, int n) {
        unordered_map<int, int> memo;
        return dfs(0, 0, m, n, memo);
    }

    int uniquePaths_2(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths3(int m, int n) {
        vector<int> dp(n);
        for (int j = 0; j < n; j++) {
            dp[j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }

    int uniquePaths(int m, int n) {
        if (m > n) {
            swap(m, n);
        }
        int ans = 1;
        int  div = 1;
        for (int i = m - 1; i > 0; i--) {
            div *= i;
            ans *= (n + i - 1);
            int g = gcd(div, ans);
            if (g > 1) {
                div /= g;
                ans /= g;
            }
        }
        return ans / div;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */

