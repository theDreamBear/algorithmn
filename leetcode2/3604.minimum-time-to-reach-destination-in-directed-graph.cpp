/*
 * @lc app=leetcode.cn id=3604 lang=cpp
 * @lcpr version=30204
 *
 * [3604] 有向图中到达终点的最少时间
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
// 妹的, pq 第一维 第二维写反了导致卡了半天
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<long long, 3>>> g(n);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1], s = edge[2], e = edge[3];
            g[u].push_back({v, s, e});
        }
        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [w, u] = pq.top(); pq.pop();
            if (dis[u] < w) continue;
            if (u == n - 1) {
                return dis[u];
            }
            for (auto& e: g[u]) {
                // 不可用
                if (w > e[2]) {
                    continue;
                }
                // <= 可以等
                long long ns = max(w, e[1]);
                if (ns + 1 < dis[e[0]]) {
                    dis[e[0]] = ns + 1;
                    pq.emplace(dis[e[0]], e[0]);
                }
            }
        }
        if (dis[n - 1] == LLONG_MAX) return -1;
        return dis[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1,0,1],[1,2,2,5]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0,1,0,3],[1,3,7,8],[0,2,1,5],[2,3,4,7]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,0,1,3],[1,2,3,5]]\n
// @lcpr case=end

 */

