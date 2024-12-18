/*
 * @lc app=leetcode.cn id=2492 lang=cpp
 * @lcpr version=30204
 *
 * [2492] 两个城市间路径的最小分数
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
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& vec: roads) {
            int f = vec[0] - 1, t = vec[1] - 1, w = vec[2];
            g[f].emplace_back(t, w);
            g[t].emplace_back(f, w);
        }
        vector<int> mark(n);
        int ans = INT_MAX;
        auto dfs = [&](auto&& dfs, int u)->void {
            mark[u] = 1;
            for (auto& adj: g[u]) {
                int v = adj.first, w = adj.second;
                ans = min(ans, w);
                if (!mark[v]) {
                    dfs(dfs, v);
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[1,2,9],[2,3,6],[2,4,5],[1,4,7]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2,2],[1,3,4],[3,4,7]]\n
// @lcpr case=end

 */

