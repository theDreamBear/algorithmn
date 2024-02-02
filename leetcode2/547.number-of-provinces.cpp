/*
 * @lc app=leetcode.cn id=547 lang=cpp
 * @lcpr version=30114
 *
 * [547] 省份数量
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    class Graph {
    public:
        int v;
        vector<vector<int>> data;

        Graph(int v) : v(v), data(v) {}

        void addEdge(int v, int w) {
            data[v].push_back(w);
            data[w].push_back(v);
        }

        int V() const {
            return v;
        }

        const vector<int>& adj(int v) const {
            return data[v];
        }

    };

    class DfsSearch {
    public:
        Graph& g;
        vector<int> marked;
        int ct = 0;

        DfsSearch(Graph& g) : g(g), marked(g.V()), ct(0) {
            for (int i = 0; i < g.V(); i++) {
                if (!marked[i]) {
                    ++ct;
                    dfs(i);
                }
            }
        }

        void dfs(int v) {
            marked[v] = 1;
            for (const auto w : g.adj(v)) {
                if (!marked[w]) {
                    dfs(w);
                }
            }
        }

        int count() const {
            return ct;
        }
    };

    int findCircleNum_dfs1(vector<vector<int>>& isConnected) {
        Graph g(isConnected.size());
        for (int v = 0; v < isConnected.size(); v++) {
            for (int w = 0; w < isConnected[v].size(); w++) {
                if (v != w and isConnected[v][w]) {
                    g.addEdge(v, w);
                }
            }
        }
        DfsSearch ds(g);
        return ds.count();
    }

    /*
        加深理解图的dfs遍历
    */
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& marked) {
        marked[i] = 1;
        for (int j = 0; j < isConnected[i].size(); j++) {
            // 筛选邻居节点
            if (marked[j] or !isConnected[i][j]) {
                continue;
            }
            dfs(j, isConnected, marked);
        }
    }

    int findCircleNum_dfs2(vector<vector<int>>& isConnected) {
        int ct = 0;
        int n = isConnected.size();
        vector<int> marked(n);
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                ++ct;
                dfs(i, isConnected, marked);
            }
        }
        return ct;
    }

    int findCircleNum_bfs(vector<vector<int>>& isConnected) {
        int ct = 0;
        int n = isConnected.size();
        // bfs 类似于地图
        vector<int> marked(n);
        for (int i = 0; i < n;  i++) {
            if (marked[i]) {
                continue;
            }
            ++ct;
            queue<int> q;
            marked[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int w = 0; w < isConnected[v].size(); w++) {
                    if (marked[w] or !isConnected[v][w]) {
                        continue;
                    }
                    marked[w] = 1;
                    q.push(w);
                }
            }
        }
        return ct;
    }

    class UF {
    public:
        vector<int> parent;
        int ct = 0;

        UF(int v): parent(v) {
            iota(parent.begin(), parent.end(), 0);
            ct = v;
        }

        int find(int v) {
            // 这个地方返回的是parent[v]
            // 因为对于第二级的节点 这个地方也会返回
            if (parent[v] == parent[parent[v]]) {
                return parent[v];
            }
            return parent[v] = find(parent[v]);
        }

        void merge(int v, int w) {
            int pv = find(v);
            int pw = find(w);
            if (pv == pw) {
                return;
            }
            --ct;
            parent[pv] = pw;
        }

        int count() const {
            return ct;
        }
    };

    /*
        并查集
    */
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UF uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.count();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */

