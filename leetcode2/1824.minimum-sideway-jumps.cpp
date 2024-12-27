/*
 * @lc app=leetcode.cn id=1824 lang=cpp
 * @lcpr version=30204
 *
 * [1824] 最少侧跳次数
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
#include <string.h>
// @lcpr-template-end
// @lc code=start
const int inf = 0x3f3f3f3f;
class Solution {
public:
    int minSideJumps_dfs(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        auto dfs = [&](auto&& dfs, int i, int j) {
            if (i == n) {
                return 0;
            }
            if (obstacles[i] == j + 1) return inf;
            auto&& ans = dp[i][j];
            if (ans != -1) return ans;
            // 直走
            ans = dfs(dfs, i + 1, j);
            for (int k = 0; k < 3; k++) {
                if (k == j) continue;
                ans = min(ans, dfs(dfs, i, k) + 1);
            }
            return ans;
        };
        return dfs(dfs, 0, 1);
    }

    int minSideJumps_dp(vector<int>& obstacles) {
        int n = obstacles.size();
        int dp[n][3];
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = dp[0][2] = 1;
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            // 前后关系
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1 or obstacles[i - 1] == j + 1) {
                    dp[i][j] = inf;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            // 横向关系
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1 or dp[i][j] != inf) {
                    continue;
                }
                int mm = inf;
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    mm = min(mm, dp[i][k] + 1);
                }
                dp[i][j] = mm;
            }
        }
        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }


    int minSideJumps_01bfs(vector<int>& obstacles) {
        int n = obstacles.size();
        int dp[n][3];
        memset(dp, 0x3f, sizeof dp);
        deque<pair<int, int>> dq;
        dq.emplace_back(0, 1);
        dp[0][1] = 0;
        for (;;) {
            auto [i, j] = dq.front(); dq.pop_front();
            int d = dp[i][j];
            if (i == n - 1) return d;
            if (obstacles[i + 1] != j + 1 and d < dp[i + 1][j]) {
                dp[i + 1][j] = d;
                dq.emplace_front(i + 1, j);
            }
            for (int k: {(j + 1) % 3, (j + 2) % 3}) {
                if (obstacles[i] != k + 1 and d + 1 < dp[i][k]) {
                    dp[i][k] = d + 1;
                    dq.emplace_back(i, k);
                }
            }
        }
    }

    // 迪杰斯特拉
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        int dp[n][3];
        memset(dp, 0x3f, sizeof dp);
        using pii = tuple<int, int, int>;
        priority_queue<pii, vector<pii>, greater<>> pq;
        dp[0][1] = 0;
        pq.emplace(0, 0, 1);
        while (!pq.empty()) {
            auto [d, i, j] = pq.top(); pq.pop();
            if (i == n - 1) return d;
            if (obstacles[i + 1] != j + 1 and d < dp[i + 1][j]) {
                dp[i + 1][j] = d;
                pq.emplace(d, i + 1, j);
            }
            for (int k: {(j + 1) % 3, (j + 2) % 3}) {
                if (obstacles[i] != k + 1 and d + 1 < dp[i][k]) {
                    dp[i][k] = d + 1;
                    pq.emplace(d + 1, i, k);
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,3,3,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,1,0,3,0]\n
// @lcpr case=end

 */

