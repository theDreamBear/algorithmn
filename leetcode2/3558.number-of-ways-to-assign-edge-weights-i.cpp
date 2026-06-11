/*
 * @lc app=leetcode.cn id=3558 lang=cpp
 * @lcpr version=30204
 *
 * [3558] 给边赋权值的方案数 I
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
    int assignEdgeWeights(vector<vector<int>>& edges) {
        // 选择奇数个位1
        // c(n, 1) + c(n, 3) + c(n, 5) + .. c(n, x);
        // 2 ^ (n - 1)
        // 求最大深度
        int n = edges.size() + 1;
        vector<vector<int>> matrix(n);
        for (auto& vec: edges) {
            matrix[vec[0] - 1].push_back(vec[1] - 1);
            matrix[vec[1] - 1].push_back(vec[0] - 1);
        }
        int start = 0;
        int max_depth = 1;
        vector<int> mark(n);
        auto dfs = [&](auto&& dfs, int x, int depth)->void {
            mark[x] = 1;
            max_depth = max(max_depth, depth);
            for (auto y: matrix[x]) {
                if (mark[y]) continue;
                dfs(dfs, y, depth + 1);
            }
        };
        dfs(dfs, 0, 0);

        auto fast = [&](long long x, long long y, int mod) {
            long long ans = 1;
            while (y) {
                if (y & 1) {
                    ans *= x;
                    ans %= mod;
                }
                y >>= 1;
                x *= x;
                x %= mod;
            }
            return ans;
        };

        return fast(2, max_depth - 1, 1e9 + 7);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[1,3],[3,4],[3,5]]\n
// @lcpr case=end

 */

