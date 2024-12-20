/*
 * @lc app=leetcode.cn id=2359 lang=cpp
 * @lcpr version=30204
 *
 * [2359] 找到离给定两个节点最近的节点
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
    // 图遍历, 枚举完一个, 统计另一个
    // 注意可能有环
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                g[i].push_back(edges[i]);
            }
        }
        unordered_map<int, int> dis;
        auto dfs = [&](auto&& dfs, int u, int d)->void {
            dis[u] = d;
            for (auto v: g[u]) {
                if (!dis.count(v)) {
                    dfs(dfs, v, d + 1);
                } else {
                    dis[v] = min(dis[v], d + 1);
                }
            }
        };
        dfs(dfs, node1, 0);
        int ans = INT_MAX, id = -1;
        vector<int> vis(n);
        auto dfs2 = [&](auto&& dfs2, int u, int d)->void {
            //if (id != -1) return;
            vis[u] = 1;
            if (dis.contains(u)) {
                int ma = max(d, dis[u]);
                if (ma < ans or (ma == ans and u < id)) {
                    ans = ma;
                    id = u;
                    //return;
                }
            }
            for (auto v: g[u]) {
                if (!vis[v]) {
                    dfs2(dfs2, v, d + 1);
                }
            }
        };
        dfs2(dfs2, node2, 0);
        return id;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,-1]\n0\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,-1]\n0\n2\n
// @lcpr case=end

 */

