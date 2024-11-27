/*
 * @lc app=leetcode.cn id=886 lang=cpp
 * @lcpr version=30204
 *
 * [886] 可能的二分法
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n);
        for (auto& vec: dislikes) {
            int f = vec[0] - 1, t = vec[1] - 1;
            g[f].push_back(t);
            g[t].push_back(f);
        }
        vector<int> color(n);
        bool ok = true;
        auto dfs = [&](auto&& dfs, int u, int c) {
            if (!ok) return;
            color[u] = c;
            for (auto v: g[u]) {
                if (!ok) return;
                if (!color[v]) {
                    dfs(dfs, v, 3 - c);
                } else if (color[v] == color[u]) {
                    ok = false;
                    return;
                }
            }
        };
        for (int i = 0; i < n and ok; i++) {
            if (!color[i]) {
                dfs(dfs, i, 1);
            }
        }
        return ok;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[1,2],[1,3],[2,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,2],[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,2],[2,3],[3,4],[4,5],[1,5]]\n
// @lcpr case=end

 */

