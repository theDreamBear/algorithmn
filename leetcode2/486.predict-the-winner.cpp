/*
 * @lc app=leetcode.cn id=486 lang=cpp
 * @lcpr version=30204
 *
 * [486] 预测赢家
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
    bool predictTheWinner1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        auto dfs = [&](auto&& dfs, int l, int r) {
            if (l >= r) return nums[l];
            if (dp[l][r] != INT_MAX) return dp[l][r];
            return dp[l][r] = max(nums[l] - dfs(dfs, l + 1, r), nums[r] - dfs(dfs, l, r - 1));
        };
        return dfs(dfs, 0, n - 1) >= 0;
    }

    bool predictTheWinner2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] >= 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,233,7]\n
// @lcpr case=end

 */

