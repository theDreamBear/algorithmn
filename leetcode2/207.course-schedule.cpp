/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30113
 *
 * [207] 课程表
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
    bool status;

    BfsTopologySearch(const DigraphDegree& g):g(g) {
        status = true;
        bfs();
    }

    bool can() const {
        return status;
    }

    void bfs() {
        auto degree = g.degree;
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < degree.size(); i++) {
            if (!degree[i]) {
                q.push(i);
                ++cnt;
            }
        }
        if (q.empty()) {
            status = false;
            return;
        }
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (const auto w : g.adj(v)) {
                if (--degree[w] == 0) {
                    q.push(w);
                    ++cnt;
                }
            }
        }
        if (cnt != g.V()) {
            status = false;
        }
        return;
    }
};

class Solution {
public:
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        Digraph g(numCourses);
        g.addEdge(prerequisites);
        TopologySearch ts(g);
        return ts.can();
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // queue;
        DigraphDegree g(numCourses);
        g.addEdge(prerequisites);
        BfsTopologySearch bs(g);
        return bs.can();
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

