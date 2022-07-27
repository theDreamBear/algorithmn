/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    // 模拟超时
    int generateTreesHelper(int low, int high) {
        if (low >= high) {
            return 1;
        }
        int ans = 0;
        for (int i = low; i <= high; i++) {
            auto left = generateTreesHelper(low, i - 1);
            auto right = generateTreesHelper(i + 1, high);
            ans += left * right;
        }
        return ans;
    }

    // 最后一个case 超时
    // 1 <= n <= 19
    // 2 ^ 19 - 1
    int numTrees_simulate(int n) {
        return generateTreesHelper(1, n);
    }

    // 动态规划
    int numTrees(int n) {
        if (n <= 1) {
            return 1;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

