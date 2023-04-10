/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    /*
     * 时间复杂度2 * 10e+7
     * */
    int findTargetSumWays1(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        cout << (1 << 20) << endl;
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) {
                    sum += nums[k];
                } else {
                    sum -= nums[k];
                }
            }
            if (sum == target) {
                ans++;
            }
        }
        return ans;
    }

       /*
    定义 dp[i][sum]前i 个的和为sum的个数
    初始化 dp[0][0] = 1, dp[0][other] = 0;
     * */
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001));
        dp[0][1000] = 1;
        for (int i = 1; i <= n; i++) {
            int po = +nums[i - 1];
            for (int j = 0; j < 2001; j++) {
                if (j >= po) {
                    dp[i][j] += dp[i - 1][j - po];
                }
                if (j + po < 2001) {
                    dp[i][j] += dp[i - 1][j + po];
                }
            }
        }
        return dp[n][target + 1000];
    }
};
// @lc code=end

