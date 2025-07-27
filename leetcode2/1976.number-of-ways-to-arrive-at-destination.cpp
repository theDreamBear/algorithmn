/*
 * @lc app=leetcode.cn id=1976 lang=cpp
 * @lcpr version=30204
 *
 * [1976] 到达目的地的方案数
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
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e: roads) {
            int u = e[0], v = e[1], c = e[2];
            g[u].emplace_back(v, c);
            g[v].emplace_back(u, c);
        }
        const long long inf = LLONG_MAX / 2;
        vector<long long> dis(n, inf);
        auto djs = [&](int x) {
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
            pq.emplace(0, x);
            dis[x] = 0;
            while (!pq.empty()) {
                auto [w, u] = pq.top(); pq.pop();
                if (dis[u] < w) continue;
                for (auto& [v, c]: g[u]) {
                    if (w + c < dis[v]) {
                        dis[v] = w + c;
                        pq.emplace(dis[v], v);
                    }
                }
            }
        };
        djs(0);
        const int mod = 1e9 + 7;
        vector<long long> f(n, inf);
        auto dfs = [&](auto&& dfs, int u)->int {
            if (u == 0) return 1;
            if (f[u] != inf) {
                return f[u];
            }
            int ans = 0;
            for (auto& [v, w]: g[u]) {
                if (dis[v] + w == dis[u]) {
                    ans = (ans + dfs(dfs, v)) % mod;
                }
            }
            return f[u] = ans;
        };
        return dfs(dfs, n - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0,10]]\n
// @lcpr case=end

 */

