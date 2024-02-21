/*
 * @lc app=leetcode.cn id=LCR 131 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 131] 砍竹子 I
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
    int cuttingBambooHelper(int bamboo_len, unordered_map<int, int>& memo) {
        if (bamboo_len <= 1) {
            return 1;
        }
        if (memo.count(bamboo_len)) {
            return memo[bamboo_len];
        }
        int ans = bamboo_len;
        for (int i = 1; i <= bamboo_len / 2; i++) {
            int val = cuttingBambooHelper(i, memo) * cuttingBambooHelper(bamboo_len - i, memo);
            ans = max(ans, val);
        }
        return memo[bamboo_len] = ans;
    }

    int cuttingBamboo1(int bamboo_len) {
        if (bamboo_len <= 1) {
            return 1;
        }
        int ans = 0;
        unordered_map<int, int> memo;
        for (int i = 1; i <= bamboo_len / 2; i++) {
            int val = cuttingBambooHelper(i, memo) * cuttingBambooHelper(bamboo_len - i, memo);
            ans = max(ans, val);
        }
        return ans;
    }

    /*
        状态:  dp[i] 长度为i, 切分为2段以上能够得到的最大长度
             max[i] 长度为i, 切分为1段及以上能够达到的最大长度

        初始化:
            dp[1] = 1   dp[2] = 1, dp[3] = 2;
            max[1] = 1, max[2] = 2, max[3] = 3;
        转态转移
            dp[i] = max[1] * max[i - 1];
            max[i] = max(dp[i], i);
        结果
            dp[n];

        优化
            i >= 4 的时候 dp[i] >= i 这时候可以把 mx给

    */
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len <= 2) {
            return 1;
        }
        if (bamboo_len == 3) {
            return 2;
        }
        vector<int> dp(bamboo_len + 1);
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for (int i = 4; i <= bamboo_len; i++) {
            for (int j = 1; j <= i >> 1; j++) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[bamboo_len];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

 */

