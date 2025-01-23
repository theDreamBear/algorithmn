/*
 * @lc app=leetcode.cn id=2920 lang=cpp
 * @lcpr version=30204
 *
 * [2920] 收集所有金币可获得的最大积分
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = edges.size() + 1;
        vector<int> pow(15);
        pow[0] = 1;
        for (int i = 1; i < 15; i++) {
            pow[i] = pow[i - 1] * 2;
        }
        vector<vector<int>> dp(n, vector<int>(15, -1));
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = coins[i];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        auto dfs = [&](auto&& dfs, int u, int t, int fa) {
            if (dp[u][t] != -1) {
                return dp[u][t];
            }
            auto& res = dp[u][t];
            res = 0;
            int b1 = coins[u] / pow[t] - k;
            int b2 = 0;
            if (t < 13) {
                b2 = coins[u] / pow[t + 1];
            }
            for (auto& [v, w]: g[u]) {
                if (v == fa) continue;
                b1 += dfs(dfs, v, t, u);
                if (t < 13) {
                    b2 += dfs(dfs, v, t + 1, u);
                }
            }
            return res = max(b1, b2);
        };
        return dfs(dfs, 0, 0, -1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[1,2],[2,3]]\n[10,10,3,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,2]]\n[8,4,4]\n0\n
// @lcpr case=end

 */

