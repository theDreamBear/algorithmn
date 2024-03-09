/*
 * @lc app=leetcode.cn id=LCR 088 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 088] 使用最小花费爬楼梯
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
    int minCostClimbingStairs1(vector<int>& cost) {
        // 只有两个数
        if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }
        int n = cost.size();
        vector<int> dp(n, INT_MAX);
        int ans = INT_MAX;
        //从0 开始
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                dp[i + 1] = min(dp[i + 1], dp[i] + cost[i]);
            }
            if (i + 2 < n) {
                dp[i + 2] = min(dp[i + 2], dp[i] + cost[i]);
            }
        }
        ans = min({dp[n - 1] + cost[n - 1], dp[n - 2] + cost[n - 2]});

        vector<int> dp2(n, INT_MAX);
        //从0 开始
        dp2[1] = 0;
        for (int i = 1; i < n; i++) {
            if (i + 1 < n) {
                dp2[i + 1] = min(dp2[i + 1], dp2[i] + cost[i]);
            }
            if (i + 2 < n) {
                dp2[i + 2] = min(dp2[i + 2], dp2[i] + cost[i]);
            }
        }
        ans = min({dp2[n - 1] + cost[n - 1], dp2[n - 2] + cost[n - 2], ans});
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, INT_MAX);
        // 逆序
        dp[0] = 0;
        for (int idx = 0; idx < cost.size(); idx++) {
            dp[idx + 1] = min(dp[idx + 1], dp[idx] + cost[idx]);
            if (idx - 1 >= 0) {
                dp[idx + 1] = min(dp[idx + 1], dp[idx -1] + cost[idx]);
            }
        }
        return min(dp[n], dp[n - 1]);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10, 15, 20]\n
// @lcpr case=end

// @lcpr case=start
// [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]\n
// @lcpr case=end

 */

