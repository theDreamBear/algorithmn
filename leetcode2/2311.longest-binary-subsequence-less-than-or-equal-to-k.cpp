/*
 * @lc app=leetcode.cn id=2311 lang=cpp
 * @lcpr version=30204
 *
 * [2311] 小于等于 K 的最长二进制子序列
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
    // 子序列, 所以错了
    int longestSubsequence_bad(string s, int k) {
        // 连续区间, 滑动窗口
        int ans = 0;
        int v = 0;
        double pow = 1;
        for (int left = 0, right = 0; right < s.size(); right++) {
            v = v * 2 + (s[right] - '0');
            pow *= 2;
            while (v > k) {
                pow /= 2;
                v -= (s[left++] - '0') * pow;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    // 哈哈哈, 脑海中设想的数位dp 居然过了
    int longestSubsequence2(string s, int k) {
        // isZero isHigh sp kp
        string t;
        while (k) {
            t.push_back((k & 1) + '0');
            k >>= 1;
        }
        ranges::reverse(t);
        int dp[2][2][1000][32];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 1000; k++) {
                    for (int m = 0; m < 32; m++) {
                        dp[i][j][k][m] = INT_MIN;
                    }
                }
            }
        }
        auto dfs = [&](auto&& dfs, int isZero, int isHigh, int sp, int tp)->int {
            if (sp >= s.size() or tp >= t.size()) {
                return 0;
            }
            if  (dp[isZero][isHigh][sp][tp] != INT_MIN) {
                return dp[isZero][isHigh][sp][tp];
            }
            // 后面可以都选了
            if (!isHigh or s.size() - sp < t.size() - tp) {
                return dp[isZero][isHigh][sp][tp] = min(s.size() - sp, t.size() - tp);
            }
            // isHigh
            // 不选
            int ans = dfs(dfs, isZero, isHigh, sp + 1, tp);
            // 选
            if (isZero and s[sp] == '0')  {
                // 直接选了
                ans++; 
            } else if (s[sp] <= t[tp]) {
                ans = max(ans, dfs(dfs, 0, s[sp] == t[tp], sp + 1, tp + 1) + 1);   
            }
            return dp[isZero][isHigh][sp][tp] = ans;
        };
        return dfs(dfs, 1, 1, 0, 0);
    }
    // 待学习
};
// @lc code=end



/*
// @lcpr case=start
// "1001010"\n5\n
// @lcpr case=end

// @lcpr case=start
// "00101001"\n1\n
// @lcpr case=end

 */

