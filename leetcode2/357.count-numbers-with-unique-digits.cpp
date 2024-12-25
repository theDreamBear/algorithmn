/*
 * @lc app=leetcode.cn id=357 lang=cpp
 * @lcpr version=30204
 *
 * [357] 统计各位数字都不同的数字个数
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
    int countNumbersWithUniqueDigits(int n) {
        string s(n, '9');
        // 
        int dp[2][2][1 << 10][20];
        memset(dp, -1, sizeof(int) * 2 * 2 * (1 << 10) * 20);

        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int mask, int pos)->int {
            if (pos >= s.size()) {
                return !isLow;
            }
            auto& ans = dp[isLow][isHigh][mask][pos];
            if (ans != -1) {
                return ans;
            }
            ans = 0;
            //  0 0   0-9
            //  0 1   0-s2
            //  1 0   0-9
            //  1 1  '0'-s2
            auto low = '0';
            auto high = isHigh ? s[pos] : '9';
            for (auto x = low; x <= high; x++) {
                if (!(isLow and x == '0') and (mask >> (x - '0')) & 1) continue;
                int newMask = isLow and x == '0' ? mask : mask | (1 << (x - '0'));
                ans += dfs(dfs, isLow and x == '0', isHigh and x == s[pos], newMask, pos + 1);
            }
            return ans;
        };
        return dfs(dfs, 1, 1, 0, 0) + 1;
    }

    int countNumbersWithUniqueDigits_v1(int n) {
                // n 减去都不一样的就行了
        string s(n, '9');
        // 
        int dp[2][2][1 << 10][20];
        memset(dp, -1, sizeof(int) * 2 * 2 * (1 << 10) * 20);

        auto dfs = [&](auto&& dfs, int isNum, int isHigh, int mask, int pos)->int {
            if (pos >= s.size()) {
                return mask > 0;
            }
            auto& ans = dp[isNum][isHigh][mask][pos];
            if (ans != -1) {
                return ans;
            }
            ans = 0;
            // 继续跳过
            if (!isNum) {
                ans = dfs(dfs, 0, 0, 0, pos + 1);
            }
            auto low =  1 - isNum + '0'; // 非数字从1开始
            auto high = isHigh ? s[pos] : '9';
            for (auto x = low; x <= high; x++) {
                if ((mask >> (x - '0')) & 1) continue;
                ans += dfs(dfs, 1, isHigh and x == s[pos], mask | (1 << (x - '0')), pos + 1);
            }
            return ans;
        };
        return dfs(dfs, 0, 1, 0, 0) + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */

