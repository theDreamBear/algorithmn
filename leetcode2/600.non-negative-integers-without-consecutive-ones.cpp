/*
 * @lc app=leetcode.cn id=600 lang=cpp
 * @lcpr version=30204
 *
 * [600] 不含连续1的非负整数
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
#include <bits/stdc++.h>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int findIntegers(int n) {
        string s;
        while (n) {
            char ch = (n & 1) + '0';
            s.push_back(ch);
            n >>= 1;
        }
        reverse(s.begin(), s.end());

        int dp[2][2][2][40];
        memset(dp, -1, sizeof(int) * 2 * 2 * 2 * 40);
        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int isSet, int pos)->int {
            if (pos >= s.size()) {
                return 1; // !isLow;
            }
            auto& ans = dp[isLow][isHigh][isSet][pos];
            if (ans != -1) {
                return ans;
            }
            ans = 0;
            // 0 0   0-1 
            // 0 1   0-s2
            // 1 0   0-1
            // 1 1   0-s2
            auto low = '0', high = s[pos];
            if (!isHigh) high = '1';
            for (auto x = low; x <= high; x++) {
                if (isSet and x == '1') {
                    continue;
                }
                ans = ans + dfs(dfs, isLow and x == '0', isHigh and x == s[pos], x == '1', pos + 1);
            }
            return ans;
        };
        return dfs(dfs, 1, 1, 0, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

