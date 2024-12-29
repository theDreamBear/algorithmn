/*
 * @lc app=leetcode.cn id=629 lang=cpp
 * @lcpr version=30204
 *
 * [629] K 个逆序对数组
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
    int kInversePairs(int n, int k) {
        // 好像会了
        // f[i, left, used]
        // 怎么快速判断使用 v, 会产生多少逆序对, 前面>v 的使用了多少个?
        vector<int> dp(k + 1);
        const int mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            vector<int> suf(k + 2);
            for (int left = k; left >= 0; left--) {
                suf[left] = (suf[left + 1] + dp[left]) % mod;
            }
            for (int left = 0; left <= k; left++) {
                dp[left] = (suf[left - min(i, left)] - suf[left + 1] + mod) % mod;
            }
        }
        return  dp[k];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n0\n
// @lcpr case=end

// @lcpr case=start
// 3\n1\n
// @lcpr case=end

 */

