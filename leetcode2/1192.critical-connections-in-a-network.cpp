/*
 * @lc app=leetcode.cn id=1192 lang=cpp
 * @lcpr version=30204
 *
 * [1192] 查找集群内的关键连接
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
class Solution1 {
public:
    vector<vector<int>> criticalConnections1(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for (auto& e: connections) {
            int u = e[0], v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int> num(n), low(n);
        vector<vector<int>> ans;
        int dfn = 0;
        auto dfs = [&](auto&& dfs, int u, int fa)->void {
            num[u] = low[u] = ++dfn;
            int child = 0;
            for (auto& v: g[u]) {
                if (!num[v]) {
                    child++;
                    dfs(dfs, v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > num[u]) {
                        ans.push_back({u, v});
                    }
                } else {
                    if (v != fa) {
                        low[u] = min(low[u], num[v]);
                    }
                }
            }
        };
        dfs(dfs, 0, -1);
        return ans;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for (auto& e: connections) {
            int u = e[0], v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int> num(n), low(n);
        vector<vector<int>> ans;
        int dfn = 0;
        auto dfs = [&](auto&& dfs, int u, int fa)->void {
            num[u] = low[u] = ++dfn;
            //int child = 0;
            for (auto& v: g[u]) {
                //if (!num[v]) {
                    //child++;
                    if (v == fa) continue;
                    if (!low[v]) dfs(dfs, v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > num[u]) {
                        ans.push_back({u, v});
                    }
                //}
            }
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};

using vi = vector<int>;
// 无线图
// 割边
vector<vector<int>> find_cut_edge(vector<vector<int>>& g) {
    int n = g.size();
    vi low(n), num(n);
    int dfn = 0, root = 0;
    vector<vi> ans;
    auto dfs = [&](auto&& dfs, int u, int fa)->void {
        num[u] = low[u] = ++dfn;
        for (auto v: g[u]) {
            // tree边
            if (!num[v]) {
                dfs(dfs, v, u);
                // 割点
                if (low[v] > num[u]) {
                    ans.push_back({min(u, v), max(u, v)});
                }
                low[u] = min(low[u], low[v]);
            // back边
            } else if (v != fa) {
                low[u] = min(low[u], num[v]);
            }
        }
    };
    dfs(dfs, root, -1);
    return ans;
}
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vi> g(n);
        for (auto& con: connections) {
            int u = con[0], v = con[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        return find_cut_edge(g);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1],[1,2],[2,0],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,1]]\n
// @lcpr case=end

 */

