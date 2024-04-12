/*
 * @lc app=leetcode.cn id=LCR 111 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 111] 除法求值
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
 class Alloc {
     public:
        int idx = 0;
        unordered_map<string, int> mp;

        int alloc(const string& key) {
            if (!contains(key)) {
                mp[key] = idx++;
            }
            return mp[key];
        }

        bool contains(const string& key) {
            return mp.count(key) > 0;
        }

        int getId(const string& key) {
            if (contains(key)) {
                return mp[key];
            }
            return -1;
        }

        int MAXID() {
            return idx;
        }
    };

    class Graph {
     public:
        int n;
        vector<vector<pair<int, double>>> adj;

        Graph(int n) : n(n), adj(n) {}


        void addEdge(int v, int w, double score) {
            adj[v].emplace_back(w, score);
            adj[w].emplace_back(v, 1 / score);
        }

        const vector<pair<int, double>>& adjacent(int v) {
            return adj[v];
        }

        int V() {
            return n;
        }
    };

    class Dfs {
     public:
        Graph& g;
        vector<int> marked;

        Dfs(Graph& g):g(g), marked(g.V()) {}

        double dfs(int v, int w) {
            if (v == w) {
                return 1;
            }
            marked[v] = 1;
            for (auto& adj : g.adjacent(v)) {
                if (!marked[adj.first]) {
                    double res = dfs(adj.first, w);
                    if (res >= 0) {
                        return res * adj.second;
                    }
                }
            }
            return -1;
        }

        double solve(int v, int w) {
            return dfs(v, w);
        }
    };


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Alloc alloc;
        for (int i = 0; i < equations.size(); i++) {
            alloc.alloc(equations[i][0]);
            alloc.alloc(equations[i][1]);

        }
        Graph g(alloc.MAXID());
        for (int i = 0; i < equations.size(); i++) {
            auto f = alloc.getId(equations[i][0]);
            auto t = alloc.getId(equations[i][1]);
            g.addEdge(f, t, values[i]);
        }
        vector<double> ans;
        map<pair<int, int>, double> memo;
        for (auto& vec : queries) {
            auto f = alloc.getId(vec[0]);
            auto t = alloc.getId(vec[1]);
            if (f == -1 || t == -1) {
                ans.push_back(-1);
                continue;
            }
            if (memo.count({f, t})) {
                ans.push_back(memo[{f, t}]);
            } else {
                Dfs dfs(g);
                ans.push_back(dfs.solve(f, t));
                memo[{f, t}] = ans.back();
                memo[{t, f}] = 1 / ans.back();
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["b","c"],["bc","cd"]]\n[1.5,2.5,5.0]\n[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"]]\n[0.5]\n[["a","b"],["b","a"],["a","c"],["x","y"]]\n
// @lcpr case=end

 */

