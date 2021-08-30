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
constexpr int MAX_N = 2e4;
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
    int max_height(vector<int>* G, int root, int n, vector<int>& temp) {
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
    //
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
        vector<bool> bad_node(n);
        for (int i = 0; i < n; i++) {
            if (bad_node[i]) {
                continue;
            }
            vector<int> temp;
            int h = max_height(G, i, n, temp);
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
};

// @lc code=end

