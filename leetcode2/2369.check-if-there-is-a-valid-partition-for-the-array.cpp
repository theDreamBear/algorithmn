/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 * @lcpr version=30204
 *
 * [2369] 检查数组是否存在有效划分
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
    bool validPartition1(vector<int>& nums) {
        int         n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (dp[i]) {
                if (nums[i] == nums[i + 1]) {
                    dp[i + 2] |= dp[i];
                    if (i + 2 < n and nums[i] == nums[i + 2]) {
                        dp[i + 3] |= dp[i];
                    }
                } else if (nums[i] + 1 == nums[i + 1] and i + 2 < n and nums[i + 1] + 1 == nums[i + 2]) {
                    dp[i + 3] |= dp[i];
                }
            }
        }
        return dp[n];
    }

    bool validPartition(vector<int>& nums) {
        int         n = nums.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i < n; i++) {
            if (f[i - 1] and nums[i] == nums[i - 1] or i > 1 and f[i - 2] and 
                (nums[i] == nums[i - 1] and nums[i] == nums[i - 2] || 
                 nums[i] == nums[i - 1] + 1 and nums[i] == nums[i - 2] + 2
            )) {
                f[i + 1] = 1;
            }
        }
        return f[n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,4,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2]\n
// @lcpr case=end

 */
