// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 * @lcpr version=30204
 *
 * [1911] 最大子序列交替和
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
    long long maxAlternatingSum1(vector<int>& nums) {
        // 0 结尾为奇数下标的最大值
        // 1 结尾为偶数下标的最大值
        // dp[i][j]
        int n = nums.size();
        long long dp[2][2]{};
        int ft = 0, st = 1;
        dp[0][1] = nums[0];
        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
            dp[st][0] = max(dp[ft][0], dp[ft][1] - nums[i]);
            dp[st][1] = max(dp[ft][1], dp[ft][0] + nums[i]);
            swap(st, ft);
        }
        return dp[ft][1];
    }

    // 记忆化
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long dp[n][2];
        for (int i = 0; i< n; i++) {
            dp[i][0] = LLONG_MIN;
            dp[i][1] = LLONG_MIN;
        }
        auto dfs = [&](auto&& dfs, int i, int j) {
            if (i < 0) {
                return 0ll;
            }
            if (dp[i][j] != LLONG_MIN) {
                return dp[i][j];
            }
            return dp[i][j] = max( dfs(dfs, i - 1, j), 
                        dfs(dfs, i - 1, !j) + (nums[i] + j * -2 * nums[i])
                        );
        };
        return dfs(dfs, n - 1, 0);
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxAlternatingSum
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [4,2,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [6,2,1,2,4,5]\n
// @lcpr case=end

 */

