/*
 * @lc app=leetcode.cn id=743 lang=cpp
 * @lcpr version=30204
 *
 * [743] 网络延迟时间
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
class Solution1 {
public:
    int networkDelayTime_dij1(vector<vector<int>>& times, int n, int k) {
        // 单源最短路径
        // dij
        vector<vector<pair<int, int>>> g(n);
        for (auto& vec: times) {
            int f = vec[0] - 1, t = vec[1] - 1, w = vec[2];
            g[f].push_back({t, w});
        }
        vector<int> dis(n, INT_MAX / 2);
        dis[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k - 1});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) continue;
            for (auto& next: g[u]) {
                int t = next.first, w = next.second;
                if (d + w >= dis[t]) continue;
                dis[t] = d + w;
                pq.push({d + w, t});
            }
        }
        int ma = ranges::max(dis);
        if (ma == INT_MAX / 2) return -1;
        return ma;
    }

    int networkDelayTime_dij2(vector<vector<int>>& times, int n, int k) {
        // 单源最短路径
        // dij
        vector<vector<pair<int, int>>> g(n);
        for (auto& vec: times) {
            int f = vec[0] - 1, t = vec[1] - 1, w = vec[2];
            g[f].push_back({t, w});
        }
        vector<int> dis(n, INT_MAX / 2), vis(n);
        dis[k - 1] = 0;
        for (int i = 1; i < n; i++) {
            int v = -1;
            for (int j = 0; j < n; j++) {
                if (!vis[j] and (v == -1 or dis[j] < dis[v])) v = j;
            }
            if (v == -1) {
                break;
            }
            vis[v] = 1;
            for (auto& next: g[v]) {
                int t = next.first, w = next.second;
                if (dis[v] + w < dis[t]) {
                    dis[t] = dis[v] + w;
                }
            }
        }
        int ma = ranges::max(dis);
        return ma == INT_MAX / 2 ? -1: ma;
    }

    int networkDelayTime_floyd(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) dis[i][i] = 0;
        for (auto& vec: times) {
            int f = vec[0] - 1, t = vec[1] - 1, w = vec[2];
            dis[f][t] = w;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int ma = 0;
        for (int i = 0; i < n; i++) {
            if (i == k -1) continue;
            ma = max(ma, dis[k - 1][i]);
        }
        return ma == INT_MAX / 2 ? -1: ma;
    }

    // 边松弛BF算法
    int networkDelayTime_BF(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<int> dis(n, INT_MAX / 2);
        dis[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int f = times[j][0] - 1, t = times[j][1] - 1, w = times[j][2];
                if (dis[t] > dis[f] + w) {
                    dis[t] = dis[f] + w;
                }
            }
        }
        int ma = ranges::max(dis);
        if (ma == INT_MAX / 2) return -1;
        return ma;
    }

        // 边松弛spfa
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto& vec: times) {
            int f = vec[0] - 1, t = vec[1] - 1, w = vec[2];
            g[f].push_back({t, w});
        }
        vector<int> dis(n, INT_MAX / 2);
        vector<int> onquene(n);
        dis[k - 1] = 0;
        onquene[k - 1] = 1;
        queue<int> q;
        q.push(k - 1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            onquene[u] = 0;
            for (auto& next: g[u]) {
                int t = next.first, w = next.second;
                if (dis[t] > dis[u] + w) {
                    dis[t] = dis[u] + w;
                    if (!onquene[t]) {
                        onquene[t] = 1;
                        q.push(t);
                    }
                }
            }
        }
        int ma = ranges::max(dis);
        if (ma == INT_MAX / 2) return -1;
        return ma;
    }
};

// dijkstra
// 适用于稠密图
// 顶点数等于 n, 边数等于 e
// 复杂度 n^2
vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
    int n = g.size();
    const int inf = INT_MAX / 2;
    vector<int> dis(n, inf), closed(n);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!closed[j] and (v == -1 or dis[j] < dis[v])) {
                v = j;
            }
        }
        if (v == -1) {
            return dis;
        }
        closed[v] = 1;
        for (auto& [to, c]: g[v]) {
            if (c + dis[v] < dis[to]) {
                dis[to] = c + dis[v];
            }
        }
    }
    return dis;
}

// dijkstra
// 适用于稀疏图
// 顶点数等于 n, 边数等于 e
// 复杂度 nlge
vector<int> dijkstra_pq(vector<vector<pair<int, int>>>& g, int s) {
    int n = g.size();
    const int inf = INT_MAX / 2;
    vector<int> dis(n, inf), closed(n);
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if (dis[u] < c) continue;
        for (auto& [to, c2]: g[u]) {
            if (c + c2 < dis[to]) {
                dis[to] = c + c2;
                pq.emplace(dis[to], to);
            }
        }
    }
    return dis;
}

// bf算法
// 优点, 可以检测到负环
vector<int> bf(vector<vector<int>>& g, int n, int s) {
    vector<int> dis(n, INT_MAX / 2);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g.size(); j++) {
            int u = g[j][0], v = g[j][1], c = g[j][2];
            if (dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }
    return dis;
}

// spfa
vector<int> spfa(vector<vector<pair<int, int>>>& g, int s) {
    vector<int> dis(g.size(), INT_MAX / 2), onstack(g.size());
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    onstack[s] = 1;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        onstack[u] = 0;
        for (auto& [v, c]: g[u]) {
            if (dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
                if (!onstack[v]) {
                    onstack[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis;
}

// floyd
vector<int> floyd(vector<vector<int>>& edges, int n, int s) {
    vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }
    for (auto e: edges) {
        int u = e[0], v = e[1], c = e[2];
        g[u][v] = c;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = g[s][i];
    }
    return ans;
}

class Solution {
public:
    int networkDelayTime_dij1(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& arr: times) {
            int u = arr[0] - 1, v = arr[1] - 1, w = arr[2];
            g[u].emplace_back(v, w);
        }
        auto dis = dijkstra(g, k - 1);
        int ma = ranges::max(dis);
        if (ma >= INT_MAX / 2) return -1;
        return ma;
    }

    int networkDelayTime_dij2(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& arr: times) {
            int u = arr[0] - 1, v = arr[1] - 1, w = arr[2];
            g[u].emplace_back(v, w);
        }
        auto dis = dijkstra_pq(g, k - 1);
        int ma = ranges::max(dis);
        if (ma >= INT_MAX / 2) return -1;
        return ma;
    }

    int networkDelayTime_bf(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> edges;
        for (auto& arr: times) {
            edges.push_back(vector<int>{arr[0] - 1, arr[1] - 1, arr[2]});
        }
        auto dis = bf(edges, n, k - 1);
        int ma = ranges::max(dis);
        if (ma >= INT_MAX / 2) return -1;
        return ma;
    }

    int networkDelayTime_spfa(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& arr: times) {
            int u = arr[0] - 1, v = arr[1] - 1, w = arr[2];
            g[u].emplace_back(v, w);
        }
        auto dis = spfa(g, k - 1);
        int ma = ranges::max(dis);
        if (ma >= INT_MAX / 2) return -1;
        return ma;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g;
        for (auto& arr: times) {
            int u = arr[0] - 1, v = arr[1] - 1, w = arr[2];
            g.push_back({u, v, w});
        }
        auto dis = floyd(g, n, k - 1);
        int ma = ranges::max(dis);
        if (ma >= INT_MAX / 2) return -1;
        return ma;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[2,3,1],[3,4,1]]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n2\n
// @lcpr case=end

 */

