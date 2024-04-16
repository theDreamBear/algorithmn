/*
 * @lc app=leetcode.cn id=LCR 104 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 104] 组合总和 Ⅳ
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
    int combinationSum41(vector<int>& nums, int target) {
        // 爬楼梯问题
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto v : nums) {
                if (i >= v) {
                    // 防止溢出
                    // if (INT_MAX - dp[i] >= dp[i - v]) {
                    //     dp[i] += dp[i - v];
                    // } else {
                    //     dp[i] = INT_MAX;
                    // }
                    dp[i] = INT_MAX - dp[i] < dp[i - v] ? INT_MAX : dp[i] + dp[i - v];
                }
            }
        }
        return dp.back();
    }

    int combinationSum4(vector<int>& nums, int target) {
        // 爬楼梯问题
        vector<unsigned int> dp(2001);
        dp[1000] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto v : nums) {
                dp[i + 1000] += dp[i + 1000 - v];
            }
        }
        return dp[1000 + target];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */

