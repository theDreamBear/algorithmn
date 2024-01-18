/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution1 {
public:
    /*
     *   返回先手最大值
     * */
    int PredictTheWinnerHelper(int low, int high, const vector<int>& nums) {
        if (low > high) {
            return 0;
        }
        int left = nums[low] - PredictTheWinnerHelper(low + 1, high, nums);
        int right = nums[high] - PredictTheWinnerHelper(low, high - 1, nums);
        return max(left, right);
    }

    bool PredictTheWinner(vector<int>& nums) {
        return PredictTheWinnerHelper(0, nums.size() - 1, nums) >= 0;
    }
};

class Solution {
public:
    /*
     *   返回先手最大值
     * */
    int PredictTheWinnerHelper(int low, int high, unordered_map<int64_t, int>& mp, const vector<int>& nums) {
        if (low > high) {
            return 0;
        }
        int64_t key = low * 10e7 + high;
        if (mp.count(key)) {
            //cout << "exist" << endl;
            return mp[key];
        }
        int left = nums[low] - PredictTheWinnerHelper(low + 1, high, mp, nums);
        int right = nums[high] - PredictTheWinnerHelper(low, high - 1, mp, nums);
        mp[key] = max(left, right);
        return mp[key];
    }

    bool PredictTheWinner_dfs(vector<int>& nums) {
        unordered_map<int64_t, int> mp;
        return PredictTheWinnerHelper(0, nums.size() - 1, mp, nums) >= 0;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            for (int j = 0; j < i; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
// @lc code=end

