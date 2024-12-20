/*
 * @lc app=leetcode.cn id=2360 lang=cpp
 * @lcpr version=30204
 *
 * [2360] 图中的最长环
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
    int longestCycle1(vector<int>& edges) {
        // 最多只有一个环 错的
        // 拓扑
        int n  =edges.size();
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                g[i].push_back(edges[i]);
                deg[edges[i]]++;
            }
        }
        // 拓扑排序减掉多余节点
        queue<int> q;
        int res = n;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                res--;
            }
        }
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto& v: g[u]) {
                if (--deg[v] == 0) {
                    q.push(v);
                    res--;
                }
            }
        }
        if (res == 0) {
            return -1;
        }
        vector<int> vis(n);
        auto dfs = [&](auto&& dfs, int u)->int {
            vis[u] = 1;
            int res = 1;
            for (auto v: g[u]) {
                if (!vis[v]) {
                    res += dfs(dfs, v);
                }
            }
            return res;
        };
        int ma = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] > 0 and !vis[i]) {
                ma = max(ma, dfs(dfs, i));
            }
        }
        return ma;
    }

    int longestCycle2(vector<int>& edges) {
        // 最多只有一个环 错的
        // 拓扑
        int n  =edges.size();
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                deg[edges[i]]++;
            }
        }
        // 拓扑排序减掉多余节点
        queue<int> q;
        int res = n;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                res--;
            }
        }
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            int v = edges[u];
            if (v == -1) {
                continue;
            }
            if (--deg[v] == 0) {
                q.push(v);
                res--;
            }
        }
        if (res == 0) {
            return -1;
        }
        int ma = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] > 0) {
                deg[i] = 0;
                int sz = 1;
                for (int x = edges[i]; x != i; x = edges[x]) {
                    deg[x] = 0;
                    sz++;
                }
                ma = max(ma, sz);
            }
        }
        return ma;
    }

    int longestCycle(vector<int>& edges) {
        // 最多只有一个环 错的
        // 拓扑
        int n  =edges.size();
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                deg[edges[i]]++;
            }
        }
        vector<int> timer(n);
        int ti = 1;
        int ma = -1;
        for (int i = 0; i < n; i++) {
            if (deg[i] > 0) {
                deg[i] = 0;
                for (int x = i, st = ti; x >= 0; x = edges[x]) {
                    if (timer[x]) {
                        if (timer[x] >= st) {
                            ma = max(ma, ti - timer[x]);
                        }
                        break;
                    }
                    timer[x] = ti++;
                }
            }
        }
        return ma;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,3,4,2\n[2,-1,3,1]\n
// @lcpr case=end

 */

