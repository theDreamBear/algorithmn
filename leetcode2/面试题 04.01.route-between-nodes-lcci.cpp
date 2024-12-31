/*
 * @lc app=leetcode.cn id=面试题 04.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.01] 节点间通路
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
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> g(n);
        for (auto& edge: graph) {
            int from = edge[0], to = edge[1];
            g[from].push_back(to);
        }
        vector<int> mark(n);
        auto dfs = [&](auto&& dfs, int u) {
            if (u == target) return true;
            mark[u] = 1;
            for (auto v: g[u]) {
                if (!mark[v]) {
                    if (dfs(dfs, v)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(dfs, start);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0, 1], [0, 2], [1, 2], [1, 2]]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]]\n0\n4\n
// @lcpr case=end

 */

