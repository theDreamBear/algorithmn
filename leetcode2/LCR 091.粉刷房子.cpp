/*
 * @lc app=leetcode.cn id=LCR 091 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 091] 粉刷房子
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
    int minCost1(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }

    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> dp(3);
        dp[0] = costs[0][0];
        dp[1] = costs[0][1];
        dp[2] = costs[0][2];
        for (int i = 1; i < costs.size(); i++) {
            int r = costs[i][0] + min(dp[1], dp[2]);
            int b = costs[i][1] + min(dp[0], dp[2]);
            int g = costs[i][2] + min(dp[0], dp[1]);

            dp[0] = r;
            dp[1] = b;
            dp[2] = g;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[17,2,17],[16,16,5],[14,3,19]]\n
// @lcpr case=end

// @lcpr case=start
// [[7,6,2]]\n
// @lcpr case=end

 */

