/*
 * @lc app=leetcode.cn id=1492 lang=cpp
 *
 * [1492] n 的第 k 个因子
 */

// @lc code=start
class Solution {
 public:
    int kthFactor(int n, int k) {
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0 && --k == 0) {
                ans = i;
            }
        }
        return ans;
    }
};
// @lc code=end

