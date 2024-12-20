/*
 * @lc app=leetcode.cn id=2127 lang=cpp
 * @lcpr version=30204
 *
 * [2127] 参加会议的最多员工数
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
    // 1 环长度>2
    // 2.环长度等于2, 需要拼接
    int maximumInvitations1(vector<int>& favorite) {
        // 最多只有一个相邻不喜欢
        int n  = favorite.size();
        vector<vector<int>> g(n);
        vector<vector<int>> rg(n);
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            if (favorite[i] != -1) {
                g[i].push_back(favorite[i]);
                deg[favorite[i]]++;
                rg[favorite[i]].push_back(i);
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
        auto depth = [&](auto&& depth, int u, int fa)->int {
            int res = 1;
            for (auto v: rg[u]) {
                if (v != fa) {
                    res = max(depth(depth, v, u) + 1, res);
                }
            }
            return res;
        };
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] > 0 and !vis[i]) {
                int v = dfs(dfs, i);
                if (v == 2) {
                    // 单链长度
                    add += depth(depth, i, g[i][0]) + depth(depth, g[i][0], i);
                }
                ma = max(ma, v);
            }
        }
        // ma这个是单环的所有结果
        // 情况二是 相互喜欢的两个点进行拼接
        ma = max(ma, add);
        return ma;
    }

    int maximumInvitations(vector<int>& favorite) {
        // 最多只有一个相邻不喜欢
        int n  = favorite.size();
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            if (favorite[i] != -1) {
                deg[favorite[i]]++;
            }
        }
        // 拓扑排序减掉多余节点
        queue<int> q;
        int res = n;
        vector<int> dis(n, 1);
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                res--;
            }
        }
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            int v = favorite[u];
            dis[v] = dis[u] + 1;
            if (--deg[v] == 0) {
                q.push(v);
                res--;
            }
        }
        if (res == 0) {
            return -1;
        }
        int ma = 0;
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] > 0) {
                deg[i] = 0;
                int sz = 1;
                for (int x = favorite[i]; x != i; x = favorite[x]) {
                    deg[x] = 0;
                    sz++;
                }
                if (sz == 2) {
                    // 单链长度
                    add += (dis[i] + dis[favorite[i]]);
                } else {
                    ma = max(ma, sz);
                }
            }
        }
        // ma这个是单环的所有结果
        // 情况二是 相互喜欢的两个点进行拼接
        ma = max(ma, add);
        return ma;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,0,1,4,1]\n
// @lcpr case=end

 */

