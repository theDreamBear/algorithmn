/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
 public:
    int subtractProductAndSum(int n) {
        int sum = 0, multi = 1;
        while (n) {
            int one = n % 10;
            n /= 10;
            sum += one;
            multi *= one;
        }
        return multi - sum;
    }
};
// @lc code=end

