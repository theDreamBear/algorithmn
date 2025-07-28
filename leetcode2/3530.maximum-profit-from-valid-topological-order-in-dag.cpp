/*
 * @lc app=leetcode.cn id=3530 lang=cpp
 * @lcpr version=30204
 *
 * [3530] 有向无环图中合法拓扑排序的最大利润
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
    int maxProfit1(int n, vector<vector<int>>& edges, vector<int>& score) {
        // 特殊处理
        if (edges.empty()) {
            ranges::sort(score);
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += score[i] * (i + 1);
            }
            return ans;
        }
        // 怎么处理拓扑排序相关逻辑
        //vector<vector<int>> g(n);
        vector<int> pre(n);
        for (auto& e: edges) {
            //g[e[0]].push_back(e[1]);
            pre[e[1]] |= (1 << e[0]);
        }
        // 
        vector<int> f(1 << n, INT_MIN / 2);
        f[0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int len = __builtin_popcount(mask);
            int high = 32 - __builtin_clz(mask);
            for (int j = 0; j < high; j++) {
                if (mask & (1 << j) and ((mask | pre[j]) == mask)) {
                    f[mask] = max(f[mask], f[mask ^ (1 << j)] + score[j] * len);
                }
            }
        }
        return f.back();
    }

    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        // 特殊处理
        if (edges.empty()) {
            ranges::sort(score);
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += score[i] * (i + 1);
            }
            return ans;
        }
        // 怎么处理拓扑排序相关逻辑
        vector<int> pre(n);
        for (auto& e: edges) {
            pre[e[1]] |= (1 << e[0]);
        }
        // 
        vector<int> f(1 << n, INT_MIN);
        auto dfs = [&](this auto&& dfs, int mask) {
            auto& ans = f[mask];
            if (ans != INT_MIN) {
                return ans;
            }
            ans = 0;
            int len = __builtin_popcount(mask);
            for (int j = 0; j < n; j++) {
                if ((mask >> j & 1) == 0 and (mask | pre[j]) == mask) {
                    ans = max(ans, dfs(mask ^ (1 << j)) + score[j] * (len + 1));
                }
            }
            return ans;
        };
        return dfs(0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[0,1]]\n[2,3]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[0,2]]\n[1,6,3]\n
// @lcpr case=end

 */

