/*
 * @lc app=leetcode.cn id=LCR 106 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 106] 判断二分图
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
    bool dfs(vector<int>& marked ,int u, int color, vector<vector<int>>& graph) {
        marked[u] = color;
        for (auto v : graph[u]) {
            if (marked[v] == 0) {
                if (!dfs(marked, v, -color, graph)) {
                    return false;
                }
            } else if (marked[v] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> marked(n);
        for (int i = 0; i < n; i++) {
            if (!marked[i] and !dfs(marked, i, 1, graph)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[0,2],[0,1,3],[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0,2],[1,3],[0,2]]\n
// @lcpr case=end

 */

