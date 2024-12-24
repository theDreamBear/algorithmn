/*
 * @lc app=leetcode.cn id=2376 lang=cpp
 * @lcpr version=30204
 *
 * [2376] 统计特殊整数
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 写错了 ans = 应该是 ans += 
    int countSpecialNumbers1(int n) {
        string s = to_string(n);
        int hs[2][2][20][1 << 10];
        memset(hs, -1, sizeof (int) * 2 * 2 * 20 * (1 << 10));
        auto dfs = [&](auto&& dfs, int isNull, int isHigh, int pos, int mask)->int {
            if (pos >= s.size()) {
                return mask > 0;
            }
            if (hs[isNull][isHigh][pos][mask] != -1) {
                return hs[isNull][isHigh][pos][mask];
            }
            //  0 0  0 - 9
            //  0 1  0 - s2
            //  1 0  0 - 9
            //  1 1  0 0 s2
            int low = '0', high = s[pos];
            if (!isHigh) high = '9';
            int ans = 0;
            for (auto x = low; x <= high; x++) {
                if (!(isNull and x == '0') and (mask & (1 << (x - '0')))) {
                    continue;
                }
                // 前缀0需要忽略
                int newMask = (isNull and x == '0') ? 0 :  mask | (1 << (x - '0'));
                ans += dfs(dfs, isNull and x == '0', isHigh and x == s[pos], pos + 1, newMask);
            }
            return hs[isNull][isHigh][pos][mask] = ans;
        };
        return dfs(dfs, 1, 1, 0, 0);
    }

        // 写错了 ans = 应该是 ans += 
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int hs[2][20][1 << 10];
        memset(hs, -1, sizeof (int) * 2 * 20 * (1 << 10));
        auto dfs = [&](auto&& dfs, int isNull, int isHigh, int pos, int mask)->int {
            if (pos >= s.size()) {
                return mask > 0;
            }
            if (hs[isHigh][pos][mask] != -1) {
                return hs[isHigh][pos][mask];
            }
            //  0 0  0 - 9
            //  0 1  0 - s2
            //  1 0  0 - 9
            //  1 1  0 0 s2
            int low = '0', high = s[pos];
            if (!isHigh) high = '9';
            int ans = 0;
            for (auto x = low; x <= high; x++) {
                if (!(isNull and x == '0') and (mask & (1 << (x - '0')))) {
                    continue;
                }
                // 前缀0需要忽略
                int newMask = (isNull and x == '0') ? 0 :  mask | (1 << (x - '0'));
                ans += dfs(dfs, isNull and x == '0', isHigh and x == s[pos], pos + 1, newMask);
            }
            return hs[isHigh][pos][mask] = ans;
        };
        return dfs(dfs, 1, 1, 0, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 20\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 135\n
// @lcpr case=end

 */

