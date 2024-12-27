/*
 * @lc app=leetcode.cn id=1320 lang=cpp
 * @lcpr version=30204
 *
 * [1320] 二指输入的的最小距离
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
int dp[310][6][7][6][7];
class Solution {
public:
    int minimumDistance(string word) {
        // f[i, x1, y1, x2, y2]
        vector<string> board{
            "ABCDEF",
            "GHIJKL",
            "MNOPQR",
            "STUVWX",
            "YZ",
        };
        unordered_map<char, pair<int, int>> pos;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                pos[board[i][j]] = make_pair(i + 1, j + 1);
            }
        }
        memset(dp, -1, sizeof dp);
        auto getDis = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };

        auto dfs = [&](auto&& dfs, int i, int x1, int y1, int x2, int y2) {
            if (i >= word.size()) {
                return 0;
            }
            auto& ans = dp[i][x1][y1][x2][y2];
            if (ans != -1) return ans;
            ans = INT_MAX;
            auto [x, y] = pos[word[i]];
            // 使用指头1
            if (x1 == 0 and y1 == 0) {
                ans = min(ans, dfs(dfs, i + 1, x, y, x2, y2));
            } else {
                ans = min(ans, dfs(dfs, i + 1, x, y, x2, y2) + getDis(x, y, x1, y1));
            }
            // 使用指头2
            if (x2 == 0 and y2 == 0) {
                ans = min(ans, dfs(dfs, i + 1, x1, y1, x, y));
            } else {
                ans = min(ans, dfs(dfs, i + 1, x1, y1, x, y) + getDis(x, y, x2, y2));
            }
            return ans;
        };
        return dfs(dfs, 0, 0, 0, 0, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "CAKE"\n
// @lcpr case=end

// @lcpr case=start
// "HAPPY"\n
// @lcpr case=end

 */

