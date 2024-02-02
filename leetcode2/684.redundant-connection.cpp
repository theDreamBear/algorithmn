/*
 * @lc app=leetcode.cn id=684 lang=cpp
 * @lcpr version=30114
 *
 * [684] 冗余连接
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
    class UF {
    public:
        vector<int> parent;
        vector<int> weight;

        UF(int n):parent(n + 1), weight(n + 1) {
            iota(parent.begin(), parent.end(), 0);
            fill(weight.begin(), weight.end(), 0);
        }

        int find(int v) {
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
            if (weight[pv] <= weight[pw]) {
                parent[pw] = pv;
                weight[pw]++;
            } else {
                parent[pv] = pw;
                weight[pv]++;
            }
        }

        bool isConnected(int v, int w) {
            return find(v) == find(w);
        }
    };

    vector<int> findRedundantConnection_uf(vector<vector<int>>& edges) {
        int n = edges.size();
        UF uf(n);
        vector<int> ans;
        for (auto& vec : edges) {
            int v = vec[0];
            int w = vec[1];
            if (uf.isConnected(v, w)) {
                ans = vec;
            } else {
                uf.merge(v, w);
            }
        }
        return ans;
    }

    class Graph {
    public:
        vector<vector<int>> data;
        int v;

        Graph(int n):data(n + 1), v(n + 1) {}

        void addEdge(int v, int w) {
            data[v].push_back(w);
            data[w].push_back(v);
        }

        int V() const {
            return v;
        }

        const vector<int>& adj(int v) {
            return data[v];
        }
    };

    class CycleSearch {
    public:
        Graph& g;
        vector<int> edgeTo;
        vector<int> onStack;
        vector<int> marked;
        UF uf;
        bool flag = false;

        CycleSearch(Graph& g): g(g), edgeTo(g.V()), onStack(g.V()), marked(g.V()), uf(g.V()) {
            flag = false;
            for (int i = 1; i < g.V() && !flag; i++) {
                if (!marked[i]) {
                    dfs(i, -1);
                }
            }
        }

        /*
        有问题的代码：

         void dfs(int v, int pa) {
            if (flag) {
                return;
            }
            marked[v] = 1;
            onStack[v] = 1;
            for (const auto w : g.adj(v)) {
                if (!marked[w]) {
                    edgeTo[w] = v;
                    dfs(w, v);
                } else if (w != pa and onStack[w]) {
                    // find cycle
                    flag = true;
                    uf.merge(v, w);
                    int p, x;
                    for (p = v, x = edgeTo[p]; x != w; p = x, x = edgeTo[p]) {
                        uf.merge(p, x);
                    }
                    uf.merge(p, x);
                    // 这个返回有问题， 需要改成break， 因为这个地方返回导致 onStack[v]状态没有恢复
                    // 且这个地方返回， 并不会导致上层dfs的循环返回
                    // 如果在for 循环的开始进行判断也能解决问题
                    return;
                }
            }
            onStack[v] = 0;
        }


        */

        void dfs(int v, int pa) {
            if (flag) {
                return;
            }
            marked[v] = 1;
            onStack[v] = 1;
            for (const auto w : g.adj(v)) {
                if (flag) {
                    return;
                }
                if (!marked[w]) {
                    edgeTo[w] = v;
                    dfs(w, v);
                } else if (w != pa and onStack[w]) {
                    // find cycle
                    flag = true;
                    uf.merge(v, w);
                    int p, x;
                    for (p = v, x = edgeTo[p]; x != w; p = x, x = edgeTo[p]) {
                        uf.merge(p, x);
                    }
                    uf.merge(p, x);
                    return;
                }
            }
            onStack[v] = 0;
        }

        bool isConnected(int v, int w) {
            return uf.isConnected(v, w);
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Graph g(n);
        for (auto& vec : edges) {
            int v = vec[0];
            int w = vec[1];
            g.addEdge(v, w);
        }
        CycleSearch cs(g);
        for (auto it = edges.rbegin(); it != edges.rend(); it++) {
            if (cs.isConnected((*it)[0], (*it)[1])) {
                return *it;
            }
        }
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2], [1,3], [2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2], [2,3], [3,4], [1,4], [1,5]]\n
// @lcpr case=end

 */

