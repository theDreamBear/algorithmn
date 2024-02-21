/*
 * @lc app=leetcode.cn id=LCR 132 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 132] 砍竹子 II
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
    int cuttingBamboo_1(int bamboo_len) {
        int n = bamboo_len;
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        vector<long long> dp(n + 1);
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i >> 1; j++) {
                // 错误表示不了了
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n] % (int)(1e9 + 7);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

 */

