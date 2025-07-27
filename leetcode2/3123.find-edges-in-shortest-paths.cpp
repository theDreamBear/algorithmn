/*
 * @lc app=leetcode.cn id=3123 lang=cpp
 * @lcpr version=30204
 *
 * [3123] 最短路径中的边
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
#include <map>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<bool> findAnswer1(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> g(n);
        int i = 0;
        for (auto& e: edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w, i);
            g[v].emplace_back(u, w, i);
            i++;
        }
        vector<int> dis1(n, INT_MAX);
        auto djs = [&](auto& dis, int x) {
            dis[x] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, x);
            while (!pq.empty()) {
                auto [c, u] = pq.top(); pq.pop();
                if (dis[u] < c) continue;
                    for (auto& [v, w, i]: g[u]) {
                    if (c + w < dis[v]) {
                        dis[v] = c + w;
                        pq.emplace(dis[v], v);
                    }
                }
            }
        };
        djs(dis1, 0);
        vector<bool> ans(edges.size());
        if (dis1[n - 1] == INT_MAX) return ans;
        queue<int> q;
        q.push(n - 1);
        vector<int> vis(n);
        vis[n-1] = 1;
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto& [v, w, i]: g[u]) {
                if (dis1[v] + w != dis1[u]) {
                    continue;
                }
                ans[i] = true;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
        
    }

    vector<bool> findAnswer2(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        int i = 0;
        for (auto& e: edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
            //g2[i] = {u, v, w};
            i++;
        }
        vector<int> dis1(n, INT_MAX);
        vector<int> dis2(n, INT_MAX);
        auto djs = [&](auto& dis, int x) {
            dis[x] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, x);
            while (!pq.empty()) {
                auto [c, u] = pq.top(); pq.pop();
                if (dis[u] < c) continue;
                    for (auto& [v, w]: g[u]) {
                    if (c + w < dis[v]) {
                        dis[v] = c + w;
                        pq.emplace(dis[v], v);
                    }
                }
            }
        };
        djs(dis1, 0);
        djs(dis2, n - 1);
        vector<bool> ans(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            // 0 .... u..v .. n - 1
            if (dis1[u] != INT_MAX and dis2[v] != INT_MAX and dis1[u] + w + dis2[v] == dis1[n - 1]) {
                ans[i] = true;
            }
            if (dis1[v] != INT_MAX and dis2[u] != INT_MAX and dis1[v] + w + dis2[u] == dis1[n - 1]) {
                ans[i] = true;
            }
        }
        return ans;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            g[u].emplace_back(v, w, i);
            g[v].emplace_back(u, w, i);
        }
        vector<int> dis1(n, INT_MAX);
        //vector<int> dis2(n, INT_MAX);
        auto djs = [&](auto& dis, int x) {
            dis[x] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, x);
            while (!pq.empty()) {
                auto [c, u] = pq.top(); pq.pop();
                if (dis[u] < c) continue;
                    for (auto& [v, w, i]: g[u]) {
                    if (c + w < dis[v]) {
                        dis[v] = c + w;
                        pq.emplace(dis[v], v);
                    }
                }
            }
        };
        djs(dis1, 0);
        //djs(dis2, n - 1);
        vector<bool> ans(edges.size());
        if (dis1[n - 1] == INT_MAX) return ans;
        vector<int> vis(n);
        auto dfs = [&](auto&& dfs, int u)->void {
            vis[u] = 1;
            for (auto& [v, w, i]: g[u]) {
                if (dis1[v] + w != dis1[u]) continue;
                ans[i] = true;
                if (!vis[v]) {
                    dfs(dfs, v);
                }

            }
        };
        dfs(dfs, n - 1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[2,0,1],[0,1,1],[0,3,4],[3,2,2]]\n
// @lcpr case=end

 */

