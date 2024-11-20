/*
 * @lc app=leetcode.cn id=3249 lang=cpp
 * @lcpr version=30204
 *
 * [3249] 统计好节点的数目
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
    int countGoodNodes1(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> memo(n, INT_MAX);
        vector<vector<int>> g(n);
        for (auto& vec: edges) {
            int u = vec[0], v = vec[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0;
        auto dfs = [&](auto&& dfs, int u)->int {
            // 父节点
            memo[u] = -1;
            int cnt = -1;
            bool flag = true;
            int res = 1;
            for (auto& v: g[u]) {
                // 父节点
                if (memo[v] < 0) {
                    continue;
                }
                int nxt = dfs(dfs, v);
                if (flag and cnt != -1 and cnt != nxt) {
                    flag = false;
                } else if (flag) {
                    cnt = nxt;
                }
                res += nxt;
            }
            if (flag) {
                ans++;
            }
            return memo[u] = res;
        };
        dfs(dfs, 0);
        return ans;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto& vec: edges) {
            int u = vec[0], v = vec[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0;
        auto dfs = [&](auto&& dfs, int u, int fa)->int {
            bool flag = true;
            int res = 1, sz0 = 0;
            for (auto& v: g[u]) {
                if (v == fa) continue;
                int nxt = dfs(dfs, v, u);
                if (sz0 == 0) {
                    sz0 = nxt;
                } else if (nxt != sz0) {
                    flag = false;
                }
                res += nxt;
            }
            ans += flag;
            return res;
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]\n
// @lcpr case=end

 */

