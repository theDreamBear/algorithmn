/*
 * @lc app=leetcode.cn id=935 lang=cpp
 * @lcpr version=30204
 *
 * [935] 骑士拨号器
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
    int knightDialer(int n) {
        vector<vector<int>> dir{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
        vector<string> board{"123", "456", "789", "*0#"};
        int ans = 0;
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, INT_MIN)));
        auto dfs = [&](auto&& dfs, int i, int j, int k) {
            if (k == 1) {
                return 1;
            }
            if (dp[i][j][k] != INT_MIN) return dp[i][j][k];
            int res = 0;
            for (int t = 0; t < 8; t++) {
                int nx = i + dir[t][0];
                int ny = j + dir[t][1];
                if (nx < 0 or nx >= 4 or ny < 0 or ny >= 3 or !isdigit(board[nx][ny])) {
                    continue;
                }
                res = (res +  dfs(dfs, nx, ny, k - 1)) % mod;
            }
            return dp[i][j][k] = res;
        };
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (isdigit(board[i][j])) {
                    ans  = (ans + dfs(dfs, i, j, n)) % mod;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3131\n
// @lcpr case=end

 */

