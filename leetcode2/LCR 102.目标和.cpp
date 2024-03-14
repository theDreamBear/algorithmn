/*
 * @lc app=leetcode.cn id=LCR 102 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 102] 目标和
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
    // 超时
    int findTargetSumWays_bad(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    sum += nums[j];
                } else {
                    sum -= nums[j];
                }
            }
            if (sum == target) {
                ++ans;
            }
        }
        return ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int offset = 1000;
        vector<vector<int>> dp(n + 1, vector<int>(2001));
        dp[0][1000] = 1;
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

