/*
 * @lc app=leetcode.cn id=785 lang=cpp
 * @lcpr version=30114
 *
 * [785] 判断二分图
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
    bool dfs(int v, int c, vector<int>& marked, vector<vector<int>>& graph) {
        marked[v] = c;
        for (auto w : graph[v]) {
            if (!marked[w]) {
                // 有结果需要立刻返回
                if (!dfs(w, -c, marked, graph)) {
                    return false;
                }
            } else if (marked[w] == c) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite_dfs(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> marked(n);
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                if (!dfs(i, 1, marked, graph)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite_bfs(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> marked(n);
         for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                queue<int> q;
                int c = 1;
                marked[i] = c;
                q.push(i);
                while (!q.empty()) {
                    int nc = -c;
                    int sz = q.size();
                    for (int i = 0; i < sz; i++) {
                        auto v = q.front();
                        q.pop();
                        for (auto w : graph[v]) {
                            if (!marked[w]) {
                                marked[w] = nc;
                                q.push(w);
                            } else if (marked[w] == c) {
                                return false;
                            }
                        }
                    }
                    c = nc;
                }
            }
         }
        return true;
    }

    class UF {
    public:
        vector<int> parent;

        UF(int n):parent(n) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int v) {
            if (parent[v] == parent[parent[v]]) {
                return parent[v];
            }
            return parent[v] = find(parent[v]);
        }

        void merge(int v, int w) {
            parent[find(v)] = find(w);
        }

        bool connected(int v, int w) {
            return find(v) ==  find(w);
        }
    };

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        UF uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                uf.merge(graph[i][0], graph[i][j]);
            }
            if (!graph[i].empty() && uf.connected(i, graph[i][0])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[0,2],[0,1,3],[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0,2],[1,3],[0,2]]\n
// @lcpr case=end

 */

