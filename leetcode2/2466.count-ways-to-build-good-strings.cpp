/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 * @lcpr version=30121
 *
 * [2466] 统计构造好字符串的方案数
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
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1);
        dp[0] = 1;
        long long ans = 0;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % (int)(1e9 + 7);
            if (i >= one)  dp[i] = (dp[i] + dp[i - one]) % (int)(1e9 + 7);
            if (i >= low) ans = (ans + dp[i]) % (int)(1e9 + 7);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n3\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n1\n2\n
// @lcpr case=end

 */

