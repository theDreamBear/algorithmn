/*
 * @lc app=leetcode.cn id=902 lang=cpp
 * @lcpr version=30204
 *
 * [902] 最大为 N 的数字组合
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
    // 妹的每次都没想完全清楚
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int dp[2][2][30];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 30; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int pos)->int {
            if (pos >= s.size()) {
                return !isLow;
            }
            // memo
            if (dp[isLow][isHigh][pos] != -1) {
                return dp[isLow][isHigh][pos];
            }
            int ans = 0;
         // isLow isHigh
        //  0     0      0-9
        //  0     1      0-s2
        //  1     0      0-9
        //  1     1      0-s2
            auto low = '0', high = s[pos];
            if (!isLow) {
                if (!isHigh) {
                    high = digits.back()[0];
                }
            } else {
                if (!isHigh) {
                    high = digits.back()[0];
                }
            }
            if (isLow) {
                ans += dfs(dfs, isLow, 0, pos + 1);
            }
            for (int i = 0; i < digits.size() and digits[i][0] <= high; i++) {
                ans += dfs(dfs, 0, isHigh and s[pos] == digits[i][0], pos + 1);
            }
            return dp[isLow][isHigh][pos] = ans;
        };
        return dfs(dfs, 1, 1, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["1","3","5","7"]\n100\n
// @lcpr case=end

// @lcpr case=start
// ["1","4","9"]\n1000000000\n
// @lcpr case=end

// @lcpr case=start
// ["7"]\n8\n
// @lcpr case=end

 */

