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
class Solution {
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

