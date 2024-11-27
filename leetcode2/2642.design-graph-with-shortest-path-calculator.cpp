/*
 * @lc app=leetcode.cn id=2642 lang=cpp
 * @lcpr version=30204
 *
 * [2642] 设计可以求最短路径的图类
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
class Graph_floyd {
public:
    vector<vector<unsigned int>> dis;

    // fioyd算法需要初始化f[i][i] = 0
    Graph_floyd(int n, vector<vector<int>>& edges): dis(n, vector<unsigned int>(n, UINT_MAX / 3)) {
        for (auto& vec: edges) {
            dis[vec[0]][vec[1]] = vec[2];
        }
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int f = edge[0], t = edge[1], w= edge[2];
        if (dis[f][t] > w) {
            dis[f][t] = w;
            int n = dis.size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][j] > dis[i][f] + w + dis[t][j]) {
                        dis[i][j] = dis[i][f] + w + dis[t][j];
                    }
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        auto v = dis[node1][node2];
        return v >= UINT_MAX / 3 ? -1 : v;
    }
};

class Graph {
public:
    vector<vector<pair<int, int>>> dis;

    Graph(int n, vector<vector<int>>& edges): dis(n) {
        for (auto& vec: edges) {
            dis[vec[0]].push_back({vec[1], vec[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        dis[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int n = dis.size();
        vector<int> d(n, INT_MAX / 2), vis(n);
        d[node1] = 0;
        bool found = false;
        for (int i = 0; !found; i++) {
            int v = -1;
            for (int j = 0; j < n; j++) {
                if (!vis[j] and (v == -1 or d[j] < d[v])) {
                    v = j;
                }
            }
            if (v == -1) {
                return -1;
            }
            vis[v] = 1;
            if (v == node2)  {
                found = true;
                break;
            }
            for (auto& adj: dis[v]) {
                int next = adj.first, w = adj.second;
                d[next] = min(d[next], d[v] + w);
            }
        }
        return d[node2] == INT_MAX / 2 ? -1: d[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end



/*
// @lcpr case=start
// ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"][[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]\n
// @lcpr case=end

 */

