/*
 * @lc app=leetcode.cn id=233 lang=cpp
 * @lcpr version=30204
 *
 * [233] 数字 1 的个数
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
    // 看清楚题目呀, 真的好难受
    int countDigitOne(int n) {
        string s = to_string(n);
        int dp[2][2][20][20];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int m = 0; m < 20; m++) {
                    for (int k = 0; k < 20; k++) {
                        dp[i][j][m][k] = -1;
                    }
                }
            }
        }
        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int oneCnt, int pos) {
            if (pos >= s.size()) {
                return oneCnt;
            }
            auto& ans = dp[isLow][isHigh][oneCnt][pos];
            if (ans != -1) {
                return ans;
            }
            ans  = 0;
            auto low = '0', high = s[pos];
            // 0 0   '0'- '9' 
            // 0 1   '0'- s2
            // 1 0    0 - 9  
            // 1 1    0 - s2
            if (!isHigh) high = '9';
            for (auto x = low; x <= high; x++) {
                ans += dfs(dfs, isLow and x == '0', isHigh and x == s[pos], oneCnt + (x == '1'), pos + 1);
            }
            return ans;
        };
        return dfs(dfs, 1, 1, 0, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 13\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */

