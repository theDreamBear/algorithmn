/*
 * @lc app=leetcode.cn id=2327 lang=cpp
 * @lcpr version=30204
 *
 * [2327] 知道秘密的人数
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
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1);
        int mod = 1e9 + 7;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (i - forget >= 1 and dp[i - forget] > 0) {
                int v = dp[i - forget];
                for (int j = i - forget; j < i; j++) {
                    dp[j] = (dp[j] - v + mod) % mod;
                }
            }
            dp[i] = dp[i - 1];
            if (i - delay >= 1) {
                dp[i] = (dp[i] + dp[i - delay]) % mod;
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n3\n
// @lcpr case=end

 */

