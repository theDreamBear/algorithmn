/*
 * @lc app=leetcode.cn id=1444 lang=cpp
 * @lcpr version=30204
 *
 * [1444] 切披萨的方案数
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

const int mod = 1e9 + 7;
class Solution {
public:
    int ways1(vector<string>& pizza, int k) {
        int dp[51][51][51][51][10];
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>> cnt(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt[i + 1][j + 1] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j] + (pizza[i][j] == 'A');
            }
        }
        memset(dp, -1, sizeof dp);
        auto get = [&](int x1, int y1, int x2, int y2) {
            return cnt[x2 + 1][y2 + 1] - cnt[x2 + 1][y1] - cnt[x1][y2 + 1] + cnt[x1][y1];
        };

        auto dfs = [&](auto&& dfs, int x1, int y1, int x2, int y2, int left) {
            // 没有苹果
            if (get(x1, y1, x2, y2) == 0) {
                return 0;
            }
            if (left == 0) {
                return 1;
            }
            auto& ans = dp[x1][y1][x2][y2][left];
            if (ans != -1) return ans;
            ans = 0;
            /// 水平
            for (int j = x1; j < x2; j++) {
                if (get(x1, y1, j, y2) and get(j + 1, y1, x2, y2)) {
                    ans = (ans + dfs(dfs, j + 1, y1, x2, y2, left - 1)) % mod;
                }
            }
            // s竖着
            for (int j = y1; j < y2; j++) {
                if (get(x1, y1, x2, j) and get(x1, j + 1, x2, y2)) {
                    ans = (ans + dfs(dfs, x1, j + 1, x2, y2, left - 1)) % mod;
                }
            }
            return ans;
        };
        return dfs(dfs, 0, 0, m - 1, n - 1, k - 1);
    }

    int ways2(vector<string>& pizza, int k) {
        int dp[51][51][10];
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>> cnt(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt[i + 1][j + 1] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j] + (pizza[i][j] == 'A');
            }
        }
        memset(dp, -1, sizeof dp);
        auto get = [&](int x1, int y1, int x2, int y2) {
            return cnt[x2 + 1][y2 + 1] - cnt[x2 + 1][y1] - cnt[x1][y2 + 1] + cnt[x1][y1];
        };

        auto dfs = [&](auto&& dfs, int x1, int y1, int left) {
            int x2 = m - 1, y2 = n - 1;
            // 没有苹果
            if (get(x1, y1, x2, y2) == 0) {
                return 0;
            }
            if (left == 0) {
                return 1;
            }
            auto& ans = dp[x1][y1][left];
            if (ans != -1) return ans;
            ans = 0;
            /// 水平
            for (int j = x1; j < x2; j++) {
                if (get(x1, y1, j, y2) and get(j + 1, y1, x2, y2)) {
                    ans = (ans + dfs(dfs, j + 1, y1, left - 1)) % mod;
                }
            }
            // s竖着
            for (int j = y1; j < y2; j++) {
                if (get(x1, y1, x2, j) and get(x1, j + 1, x2, y2)) {
                    ans = (ans + dfs(dfs, x1, j + 1, left - 1)) % mod;
                }
            }
            return ans;
        };
        return dfs(dfs, 0, 0, k - 1);
    }

    int ways(vector<string>& pizza, int k) {
        int dp[51][51];
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>> cnt(m + 1, vector<int>(n + 1));
        for (int i = m - 1; i >= 0;  i--) {
            for (int j = n - 1; j >= 0; j--) {
                cnt[i][j] = cnt[i][j + 1] + cnt[i + 1][j] - cnt[i + 1][j + 1] + (pizza[i][j] == 'A');
                if (cnt[i][j]) {
                    dp[i][j] = 1;
                }
            }
        }
        while (--k) {
            // 列的后缀和
            vector<int> col_s(n);
            for (int i = m - 1; i >= 0; i--) {
                int row_s = 0; // 行的前缀和
                for (int j = n - 1; j >= 0; j--) {
                    int tmp = dp[i][j];
                    if (cnt[i][j] == cnt[i][j + 1]) dp[i][j] = dp[i][j + 1];
                    else if (cnt[i][j] == cnt[i + 1][j]) dp[i][j] = dp[i + 1][j];
                    else {
                        dp[i][j] = (row_s + col_s[j]) % mod;
                    }
                    row_s = (row_s + tmp) % mod;
                    col_s[j] = (col_s[j] + tmp) % mod;
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["A..","AAA","..."]\n3\n
// @lcpr case=end

// @lcpr case=start
// ["A..","AA.","..."]\n3\n
// @lcpr case=end

// @lcpr case=start
// ["A..","A..","..."]\n1\n
// @lcpr case=end

 */

