/*
 * @lc app=leetcode.cn id=3218 lang=cpp
 * @lcpr version=30204
 *
 * [3218] 切蛋糕的最小总开销 I
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumCost1(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // 动态规划
        int dp[30][30][30][30];
        memset(dp, -1, sizeof(int) * 30 * 30 * 30 * 30);

        auto dfs = [&](auto&& dfs, int x1, int y1, int x2, int y2) {
            if (x1 >= x2 or y1 >= y2) return INT_MAX / 2;
            auto& ans = dp[x1][y1][x2][y2];
            if (ans != -1) {
                return ans;
            }
            ans = 0;
            // 横着的一条
            if (x1 + 1 == x2) {
                for (int j = y1; j + 1 < y2; j++) {
                    ans += verticalCut[j];
                }
                return ans;
            }
            // 竖着的一条
            if (y1 + 1 == y2) {
                for (int j = x1; j + 1 < x2; j++) {
                    ans += horizontalCut[j];
                }
                return ans;
            }
            ans = INT_MAX;
            // 横着枚举
            for (int j = x1 + 1; j < x2; j++) {
                ans = min(ans, dfs(dfs, x1, y1, j, y2) + dfs(dfs, j, y1, x2, y2) + horizontalCut[j - 1]);
            }
            // 竖着枚举
            for (int j = y1 + 1; j < y2; j++) {
                ans = min(ans, dfs(dfs, x1, y1, x2, j) + dfs(dfs, x1, j, x2, y2) + verticalCut[j - 1]);
            }
            return ans;
        };
        return dfs(dfs, 0, 0, m, n);
    }

    int minimumCost2(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // 动态规划
        int dp[30][30][30][30];
        memset(dp, -1, sizeof(int) * 30 * 30 * 30 * 30);

        auto dfs = [&](auto&& dfs, int x1, int y1, int x2, int y2) {
            if (x1 >= x2 or y1 >= y2) return INT_MAX / 2;
            auto& ans = dp[x1][y1][x2][y2];
            if (ans != -1) {
                return ans;
            }
            ans = 0;
            // 横着的一条
            if (x1 + 1 == x2) {
                for (int j = y1; j + 1 < y2; j++) {
                    ans += verticalCut[j];
                }
                return ans;
            }
            // 竖着的一条
            if (y1 + 1 == y2) {
                for (int j = x1; j + 1 < x2; j++) {
                    ans += horizontalCut[j];
                }
                return ans;
            }
            ans = INT_MAX;
            // 横着枚举, 找最大的
            int x = x1 + 1;
            for (int j = x1 + 1; j < x2; j++) {
                if (horizontalCut[j - 1] > horizontalCut[x - 1]) {
                    x = j;
                }
            }
            ans = min(ans, dfs(dfs, x1, y1, x, y2) + dfs(dfs, x, y1, x2, y2) + horizontalCut[x - 1]);
            // 竖着找最大的
            x = y1 + 1;
            for (int j = y1 + 1; j < y2; j++) {
                if (verticalCut[j - 1] > verticalCut[x - 1]) {
                    x = j;
                }
            }
            ans = min(ans, dfs(dfs, x1, y1, x2, x) + dfs(dfs, x1, x, x2, y2) + verticalCut[x - 1]);
            return ans;
        };
        return dfs(dfs, 0, 0, m, n);
    }

    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int hcnt = 1;
        int vcnt = 1;
        int ans = 0;
        ranges::sort(horizontalCut, greater<>{});
        ranges::sort(verticalCut, greater<>{});
        int i = 0, j = 0;
        while (i < horizontalCut.size() or j < verticalCut.size()) {
            int lv = i < horizontalCut.size() ? horizontalCut[i] : 0;
            int rv = j < verticalCut.size() ? verticalCut[j]: 0;
            if (lv >= rv) {
                ans += vcnt * lv;
                hcnt++;
                i++;
            } else {
                ans += hcnt * rv;
                vcnt++;
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n[1,3]\n[5]\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n[7]\n[4]\n
// @lcpr case=end

 */

