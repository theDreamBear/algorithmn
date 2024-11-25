/*
 * @lc app=leetcode.cn id=1510 lang=cpp
 * @lcpr version=30204
 *
 * [1510] 石子游戏 IV
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
    bool winnerSquareGame(int n) {
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j * j <= i and !dp[i]; j++) {
                dp[i] |= !dp[i - j * j];
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 17\n
// @lcpr case=end

 */

