/*
 * @lc app=leetcode.cn id=2719 lang=cpp
 * @lcpr version=30204
 *
 * [2719] 统计整数数目
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
    // 哈哈哈, 45分钟. 但是还是出来啦
    int count(string num1, string num2, int min_sum, int max_sum) {
        int mod = 1e9 + 7;
        int m = num1.size(), n = num2.size();
        if (m < n) {
            num1 = string(n - m, '0') + num1;
        }
        int dp[30][2][2][500];
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int m = 0; m < 500; m++) {
                        dp[i][j][k][m] = -1;
                    }
                }
            }
        }
        // 一样长了
        //
        // low  0    0      1       1
        // high 0    1      0       1
        //      0-9  0-s2  s1-9    s1-s2
        auto dfs = [&](auto&& dfs, int pos, int isLow, int isHigh, int ds)->int {
            if (pos >= n) {
                return ds >= min_sum and ds <= max_sum;
            }
            if (ds > max_sum) return 0;
            if (dp[pos][isLow][isHigh][ds] != -1) {
                return dp[pos][isLow][isHigh][ds];
            }
            auto low = num1[pos], high = num2[pos];
            if (!isHigh) {
                high = '9';
                if (!isLow) low = '0';
            } else {
                if (!isLow) {
                    low = '0';
                }
            }
            // 范围OK了
            long long ans = 0;
            for (auto x = low; x <= high; x++) {
                ans = (ans + dfs(dfs, pos + 1, isLow and x == num1[pos], isHigh and x == num2[pos], ds + (x - '0'))) % mod;
            }
            return dp[pos][isLow][isHigh][ds] = ans;
        };
        return dfs(dfs, 0, 1, 1, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1"\n"12"\n1\n8\n
// @lcpr case=end

// @lcpr case=start
// "1"\n"5"\n1\n5\n
// @lcpr case=end

 */

