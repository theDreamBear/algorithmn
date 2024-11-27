/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30114
 *
 * [210] 课程表 II
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
class Digraph {
public:
    int vnt;
    vector<vector<int>> data;

    Digraph(int v): vnt(v), data(vnt){}

    void addEdge(int v, int w) {
        data[v].push_back(w);
    }

    void addEdge(const vector<vector<int>>& edges) {
        for (const auto& vec : edges) {
            addEdge(vec[1], vec[0]);
        }
    }

    const vector<int>& adj(int v) const{
        return data[v];
    }

    int V() const {
        return vnt;
    }
};

class TopologySearch {
public:
    const Digraph& g;
    vector<int> marked;
    vector<int> onStack;
    bool status;
    stack<int> reverse_post;

    void dfs(int v) {
        if (!status) {
            return;
        }
        marked[v] = 1;
        onStack[v] = 1;
        for (const int w : g.adj(v)) {
            if (!marked[w]) {
                dfs(w);
                continue;
            }
            if (onStack[w]) {
                status = false;
                return;
            }
        }
        reverse_post.push(v);
        onStack[v] = 0;
    }

    TopologySearch(const Digraph& g): g(g), marked(g.V()), onStack(g.V()){
        status = true;
        for (int v = 0; status && v < g.V(); v++) {
            if (!marked[v]) {
                dfs(v);
            }
        }
    }

    bool can() {
        return status;
    }

    vector<int> topologySort() {
        vector<int> ans;
        if (!status) {
            return ans;
        }
        while (!reverse_post.empty()) {
            ans.push_back(reverse_post.top());
            reverse_post.pop();
        }
        return ans;
    }
};

class DigraphDegree {
public:
    int vnt;
    vector<vector<int>> data;
    vector<int> degree;

    DigraphDegree(int v): vnt(v), data(vnt), degree(vnt){}

    void addEdge(int v, int w) {
        data[v].push_back(w);
        ++degree[w];
    }

    void addEdge(const vector<vector<int>>& edges) {
        for (const auto& vec : edges) {
            addEdge(vec[1], vec[0]);
        }
    }

    const vector<int>& adj(int v) const{
        return data[v];
    }

    int V() const {
        return vnt;
    }
};

class BfsTopologySearch {
public:
    const DigraphDegree& g;
    vector<int> ans;

    BfsTopologySearch(const DigraphDegree& g):g(g) {
        bfs();
        if (!can()) {
            ans.clear();
        }
    }

    bool can() const {
        return ans.size() == g.V();
    }

    void bfs() {
        auto degree = g.degree;
        queue<int> q;
        for (int i = 0; i < degree.size(); i++) {
            if (!degree[i]) {
                ans.push_back(i);
                q.push(i);
            }
        }
        if (q.empty()) {
            return;
        }
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (const auto w : g.adj(v)) {
                if (--degree[w] == 0) {
                    ans.push_back(w);
                    q.push(w);
                }
            }
        }
        return;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Digraph g(numCourses);
        g.addEdge(prerequisites);
        TopologySearch ts(g);
        return ts.topologySort();
    }

    vector<int> findOrder1(int numCourses, vector<vector<int>>& prerequisites) {
        DigraphDegree g(numCourses);
        g.addEdge(prerequisites);
        BfsTopologySearch bs(g);
        return bs.ans;
    }


};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */

