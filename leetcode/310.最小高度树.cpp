/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
constexpr int MAX_N = 2e4 + 1;
int q[MAX_N];

class myQueue {
private:
    int head;
    int tail;
public:
    myQueue() {
        head = 0;
        tail = 0;
    }

    void push(int val) {
        q[tail++] = val;
    }

    bool empty() {
        return tail == head;
    }

    int size() {
        return tail - head;
    }

    int front() {
        return q[head];
    }

    void pop() {
        ++head;
    }
};

class Solution {
public:
    // 返回从i 节点出发树的最深长度
    int min_height(vector<int> *G, int root, int n, vector<int> &temp) {
        // 宽度优先遍历
        int h = 0;
        vector<bool> visited(n);
        //queue<int> q;
        myQueue q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            ++h;
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                visited[node] = true;
                bool newValue = false;
                for (int successor : G[node]) {
                    if (visited[successor]) {
                        continue;
                    }
                    q.push(successor);
                    newValue = true;
                }
                if (!newValue) {
                    temp.push_back(node);
                }
            }
        }
        return h;
    }

    // 超时
    // 结果必然是最长路径的中间节点
    // 找到最长路径, 然后双向 bfs 就行
    //
    vector<int> findMinHeightTrees_bad(int n, vector<vector<int>> &edges) {
        vector<int> G[n];
        for (auto &vec : edges) {
            int f = vec[0];
            int t = vec[1];
            G[f].emplace_back(t);
            G[t].emplace_back(f);
        }
        vector<int> ans;
        int min_h = INT_MAX;
        vector<bool> bad_node(n);
        for (int i = 0; i < n; i++) {
            if (bad_node[i]) {
                continue;
            }
            vector<int> temp;
            int h = min_height(G, i, n, temp);
            if (h < min_h) {
                if (min_h != INT_MAX) {
                    for (auto v : temp) {
                        bad_node[v] = true;
                    }
                }
                ans.clear();
                min_h = h;
                ans.push_back(i);
                continue;
            }
            if (h == min_h) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    int dfs(vector<int> *G, int node, int p, unordered_map<int, int> &hash) {
        int v = node * MAX_N + p;
        if (hash.count(v) > 0) {
            return hash[v];
        }
        int ans = 0;
        for (auto successor : G[node]) {
            if (successor == p) {
                continue;
            }
            ans = max(ans, dfs(G, successor, node, hash) + 1);
        }
        return hash[v] = ans;
    }

    /*
        dfs + 记忆化搜索
    */
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<int> G[n];
        for (auto &vec : edges) {
            int f = vec[0];
            int t = vec[1];
            G[f].emplace_back(t);
            G[t].emplace_back(f);
        }
        vector<int> ans;
        int min_h = INT_MAX;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            int h = dfs(G, i, -1, hash);
            if (h < min_h) {
                min_h = h;
                ans.clear();
                ans.push_back(i);
            } else if (h == min_h) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    /*
     *  拓扑排序 + bfs 结果还行
     * */
    vector<int> findMinHeightTrees2(int n, vector<vector<int>> &edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> G[n];
        vector<int> degree(n);
        for (auto &vec : edges) {
            int f = vec[0];
            int t = vec[1];
            ++degree[f];
            ++degree[t];
            G[f].emplace_back(t);
            G[t].emplace_back(f);
        }
        vector<int> ans;
        //myQueue q;
        queue<int> q;
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] == 1) {
                q.push(i);
                --degree[i];
            }
        }
        while (!q.empty()) {
            ans.clear();
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                ans.emplace_back(node);
                q.pop();
                for (auto successor : G[node]) {
                    if (--degree[successor] == 1) {
                        q.push(successor);
                    }
                }
            }
        }
        return ans;
    }

    int bfs(vector<int> *G, int node, int n) {
        int ans = -1;
        myQueue q;
        q.push(node);
        vector<bool> visited(n);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto temp = q.front();
                visited[temp] = true;
                q.pop();
                ans = temp;
                for (auto successor : G[temp]) {
                    if (visited[successor]) {
                        continue;
                    }
                    q.push(successor);
                }
            }
        }
        return ans;
    }

    int bfs2(vector<int> *G, int node, int n, unordered_map<int, int> &hash, int &last) {
        int ans = -1;
        myQueue q;
        q.push(node);
        vector<bool> visited(n);
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto temp = q.front();
                visited[temp] = true;
                q.pop();
                last = temp;
                for (auto successor : G[temp]) {
                    if (visited[successor]) {
                        continue;
                    }
                    hash[successor] = temp;
                    q.push(successor);
                }
            }
        }
        return ans;
    }

    /*
  *  树的直径
  *  1.找到树的直径的起始节点
  *  2.记录从指定方向的最大深度
  * */
    vector<int> findMinHeightTrees_ok(int n, vector<vector<int>> &edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> G[n];
        vector<int> degree(n);
        for (auto &vec : edges) {
            int f = vec[0];
            int t = vec[1];
            ++degree[f];
            ++degree[t];
            G[f].emplace_back(t);
            G[t].emplace_back(f);
        }
        vector<int> ans;
        // 找最边缘的某一个节点
        int right = bfs(G, 0, n);
        unordered_map<int, int> hash;
        int last;
        // 找直径对应的另一个节点, 并记录每一个节点的 parent
        int len = bfs2(G, right, n, hash, last);
        int target = 0;
        while (target < len / 2) {
            ++target;
            last = hash[last];
        }
        ans.push_back(last);
        if (len % 2 != 0) {
            ans.push_back(hash[last]);
        }
        return ans;
    }

};
// @lc code=end

