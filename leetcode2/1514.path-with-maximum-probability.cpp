/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 * @lcpr version=30204
 *
 * [1514] 概率最大的路径
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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> g[n];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        auto dijkstra = [&](int start, int end)->double {
            priority_queue<pair<double, int>> pq;
            vector<double> dis(n, -1);
            dis[start] = 1;
            pq.push({1, start});
            while (!pq.empty()) {
                auto [w, u] = pq.top();
                pq.pop();
                if (w < dis[u]) {
                    continue;
                }
                if (u == end) {
                    return w;
                }
                for (auto& [v, d]: g[u]) {
                    if (dis[v] == -1 or w * d > dis[v]) {
                        dis[v] = w * d;
                        pq.push({w * d, v});
                    }
                }
            }
            return 0;
        };
        auto dijkstra2 = [&](int start, int end)->double {
            priority_queue<pair<double, int>> pq;
            vector<double> dis(n, -1);
            vector<int> vis(n);
            dis[start] = 1;
            for (int i = 0; i < n; i++) {
                int v = -1;
                for (int j = 0; j < n; j++) {
                    if (!vis[j] and (v == -1 or dis[j] > dis[v])) {
                        v = j;
                    }
                }
                if (v == -1 or dis[v] <= 0) {
                    return 0;
                }
                if (v == end) {
                    return dis[v];
                }
                vis[v] = 1;
                for (auto& [nxt, w]: g[v]) {
                    if (dis[v] * w > dis[nxt]) {
                        dis[nxt] = dis[v] * w;
                    }
                }
            }
            return 0;
        };
        return dijkstra2(start_node, end_node);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.3]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1]]\n[0.5]\n0\n2\n
// @lcpr case=end

 */

