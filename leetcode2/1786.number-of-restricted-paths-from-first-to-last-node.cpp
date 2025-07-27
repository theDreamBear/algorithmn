/*
 * @lc app=leetcode.cn id=1786 lang=cpp
 * @lcpr version=30204
 *
 * [1786] 从第一个节点出发到最后一个节点的受限路径数
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
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        // 建图
        vector<vector<pair<int, int>>> g(n);
        for (auto& e: edges) {
            int u = e[0] - 1, v = e[1] - 1, w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        // 单源最短路径, 从n出发
        vector<int> dis(n, INT_MAX);
        dis[n - 1] = 0;
        auto djs = [&]() {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, n - 1);
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
        djs();
        // f[i] 受限路径数
        // f[u] = (f[u] + f[v]) % mod if dis[u] > dis[v]
        vector<int> f(n, -1);
        const int mod = 1e9 + 7;
        auto dfs = [&](auto&& dfs, int u)->long long {
            if (u == n - 1) {
                return 1;
            }
            if (f[u] != -1) {
                return f[u];
            }
            long long ans = 0;
            for (auto& [v, w]: g[u]) {
                if (dis[u] > dis[v]) {
                    ans = (ans + dfs(dfs, v)) % mod;
                }
            }
            return f[u] = ans;
        };
        dfs(dfs, 0);
        return f[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]\n
// @lcpr case=end

 */

