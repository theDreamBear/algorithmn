/*
 * @lc app=leetcode.cn id=3332 lang=cpp
 * @lcpr version=30204
 *
 * [3332] 旅客可以得到的最多点数
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
    // 状态 (i: 当前城市, j: 当前是第几天)
    // j = k 返回0
    // 待在原地, s[j][i] + f(i, j + 1) 子状态
    // 转移,     t[i][k] + f(k, j + 1) 子状态
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        // f(i, j) 从i出发待当前为第j天能够获得的最大点数
        // f(i, j) = 待在原地 stay[j][i] + f(i, j + 1)
        //         = 去k城市  travel[i][k] + f(k, j+1)
        // f(i, k) = 0;
        //
        int dp[201][201];
        memset(dp, -1, sizeof dp);

        auto dfs = [&](auto&& dfs, int i, int j) {
            if (j == k) {
                return 0;
            }
            auto& ans = dp[i][j];
            if (ans != -1) {
                return ans;
            }
            // 待在原地
            ans = stayScore[j][i] + dfs(dfs, i, j + 1);
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                ans = max(ans, travelScore[i][k] + dfs(dfs, k, j + 1));
            }
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(dfs, i, 0));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n1\n[[2,3]]\n[[0,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n[[3,4,2],[2,1,2]]\n[[0,2,1],[2,0,4],[3,2,0]]\n
// @lcpr case=end

 */

