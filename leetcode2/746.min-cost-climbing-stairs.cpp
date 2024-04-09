/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30121
 *
 * [746] 使用最小花费爬楼梯
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
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[n - 2], dp[n - 1]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prepre = cost[0];
        int pre = cost[1];
        for (int i = 2; i < n; i++) {
            int now = min(prepre, pre) + cost[i];
            prepre = pre;
            pre = now;
        }
        return min(prepre, pre);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */

