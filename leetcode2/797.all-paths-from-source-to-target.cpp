/*
 * @lc app=leetcode.cn id=797 lang=cpp
 * @lcpr version=30204
 *
 * [797] 所有可能的路径
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
    // 注意到回溯的复杂度是
    // 2^n 所以 轻松通过
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        // 回溯所有从0 开始的路径
        vector<int> tmp{0};

        auto dfs = [&](auto&& dfs, int u) {
            if (u == n - 1) {
                ans.push_back(tmp);
                return;
            }
            for (auto& v: graph[u]) {
                tmp.push_back(v);
                dfs(dfs, v);
                tmp.pop_back();
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

 */

