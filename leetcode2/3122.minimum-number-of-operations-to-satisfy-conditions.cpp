/*
 * @lc app=leetcode.cn id=3122 lang=cpp
 * @lcpr version=30204
 *
 * [3122] 使矩阵满足条件的最少操作次数
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bits/stdc++.h>
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
    int minimumOperations1(vector<vector<int>>& grid) {
        // 一行, 变成第一多的, 第二多的, 第三多的magic
        int m = grid.size(), n = grid[0].size();
        struct Node {
            pair<int, int> pp[3];
        };
        vector<Node> cols(n);
        for (int j = 0; j < n; j++) {
            map<int, int> cnt;
            for (int i = 0; i < m; i++) {
                cnt[grid[i][j]]++;
            }
            vector<pair<int, int>> tmp;
            for (auto& kv : cnt) {
                tmp.emplace_back(kv.first, kv.second);
            }
            // 递减
            sort(tmp.begin(), tmp.end(), [&](auto& a, auto& b) { return a.second > b.second; });
            for (int k = 0; k < min((int)tmp.size(), 3); k++) {
                cols[j].pp[k] = tmp[k];
            }
            for (int k = tmp.size(); k < 3; k++) {
                cols[j].pp[k] = {10, 0};
            }
        }
        // 每一行只有三个状态, 使用第一个, 第二个, 第三个
        vector<vector<int>> dp(n + 1, vector<int>(11, -1));
        auto                dfs = [&](auto&& dfs, int i, int c) {
            if (i >= n) {
                return 0;
            }
            auto& ans = dp[i][c];
            if (ans != -1)
                return dp[i][c];
            ans = INT_MAX;
            for (int j = 0; j < 3; j++) {
                auto [v, ct] = cols[i].pp[j];
                if (v == c and v != 10) {
                    continue;
                }
                ans = min(ans, dfs(dfs, i + 1, v) + m - ct);
                if (v == 10) {
                    break;
                }
            }
            return ans;
        };
        return dfs(dfs, 0, 10);
    }

    int minimumOperations2(vector<vector<int>>& grid) {
        // 一行, 变成第一多的, 第二多的, 第三多的magic
        int m = grid.size(), n = grid[0].size();
        vector<array<int, 10>> cols(n);
        for (auto& vec: grid) {
            for (int j = 0; j < n; j++) {
                cols[j][vec[j]]++;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(11, -1));
        auto                dfs = [&](auto&& dfs, int i, int c) {
            if (i >= n) {
                return 0;
            }
            auto& ans = dp[i][c];
            if (ans != -1)
                return dp[i][c];
            ans = INT_MAX;
            for (int v = 0; v < 10; v++) {
                int ct = cols[i][v];
                if (v == c and v != 10) {
                    continue;
                }
                ans = min(ans, dfs(dfs, i + 1, v) + m - ct);
            }
            return ans;
        };
        // 当前行使用c, 修改的最小次数
        return dfs(dfs, 0, 10);
    }

    int minimumOperations(vector<vector<int>>& grid) {
        // 保留当前的, 需要修改的最少次数
        int m = grid.size(), n = grid[0].size();
        int f0 = 0, f1 = 0, val = -1;
        for (int i = 0; i < n; i++) {
            int cnt[10]{};
            for (auto& row: grid) {
                cnt[row[i]]++;
            }
            // 本次的结果
            int mx = -1, mx2 = 0, x = -1;
            for (int v = 0; v < 10; v++) {
                int res = ((v == val) ? f1: f0) + cnt[v];
                if (res > mx) {
                    mx2 = mx;
                    mx = res;
                    x = v;
                } else if (res > mx2) {
                    mx2 = res;
                }
            }
            f0 = mx;
            f1 = mx2;
            val = x;
        }
        return m * n - f0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,0,2],[1,0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[2],[3]]\n
// @lcpr case=end

 */
