/*
 * @lc app=leetcode.cn id=464 lang=cpp
 * @lcpr version=30204
 *
 * [464] 我能赢吗
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
    bool canIWin1(int maxChoosableInteger, int desiredTotal) {
        unordered_map<int, bool> dp;
        auto dfs = [&](auto&& dfs, int left, int mask) {
            if (left <= 0) return true;
            int hash = (mask << 10) + left;
            if (dp.count(hash)) return dp[hash];
            bool res = false;
            int old = mask;
            while (mask and !res) {
                int v = 32 - __builtin_clz(mask);
                if (v >= left) res = true;
                else {
                    res |= !dfs(dfs, left - v, old ^ (1 << (v - 1)));
                }
                mask ^= (1 << (v - 1));
            }
            return dp[hash] = res;
        };
        int total = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (total < desiredTotal) return false;
        return dfs(dfs, desiredTotal, (1 << maxChoosableInteger) - 1);
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        unordered_map<int, bool> dp;
        auto dfs = [&](auto&& dfs, int left, int mask) {
            if (left <= 0) return true;
            if (dp.count(mask)) return dp[mask];
            bool res = false;
            int old = mask;
            while (mask and !res) {
                int v = 32 - __builtin_clz(mask);
                if (v >= left) res = true;
                else {
                    res |= !dfs(dfs, left - v, old ^ (1 << (v - 1)));
                }
                mask ^= (1 << (v - 1));
            }
            return dp[old] = res;
        };
        int total = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (total < desiredTotal) return false;
        return dfs(dfs, desiredTotal, (1 << maxChoosableInteger) - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n11\n
// @lcpr case=end

// @lcpr case=start
// 10\n0\n
// @lcpr case=end

// @lcpr case=start
// 10\n1\n
// @lcpr case=end

 */

