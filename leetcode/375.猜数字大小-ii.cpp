/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
 public:
    int getMoneyAmountHelper(vector<vector<int>>& dp, int start, int end) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            int left = getMoneyAmountHelper(dp, start, i - 1);
            int right = getMoneyAmountHelper(dp, i + 1, end);
            ans = min(ans, max(left, right) + i);
        }
        return dp[start][end] = ans;
    }

    /* 返回目标值是任意值的最大代价
     * */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return getMoneyAmountHelper(dp, 1, n);
    }
};
// @lc code=end

