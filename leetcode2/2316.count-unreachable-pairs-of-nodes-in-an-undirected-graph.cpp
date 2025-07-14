/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 * @lcpr version=30204
 *
 * [2316] 统计无向图中无法互相到达点对数
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        // 找到所有的环, 计算大小
        //int n = edges.size();
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            int f = e[0], t = e[1];
            g[f].push_back(t);
            g[t].push_back(f);
        }
        long long ans = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                long long cnt = 0;
                auto dfs = [&](auto&& dfs, int u)->void {
                    vis[u] = 1;
                    cnt++;
                    for (auto& v: g[u]) {
                        if (!vis[v]) {
                            dfs(dfs, v);
                        }
                    }
                };
                dfs(dfs, i);
                ans += cnt * (n - cnt);
            }
        }
        return ans >> 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1],[0,2],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[[0,2],[0,5],[2,4],[1,6],[5,4]]\n
// @lcpr case=end

 */

