/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 *
 * https://leetcode-cn.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (65.09%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    28.9K
 * Total Submissions: 44.3K
 * Testcase Example:  '38'
 *
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
 * 
 * 示例:
 * 
 * 输入: 38
 * 输出: 2 
 * 解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
 * 
 * 
 * 进阶:
 * 你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        #define MACRO1
        #ifdef MACRO
        // 暴力解法
        while (10 <= num) {
            int temp = 0;
            while (0 != num) {
                temp += (num % 10);
                num /= 10;
            }
            num = temp;
        }
        // num < 10 得到结果
        return num;
        #endif  //  MACRO

        #ifdef MACRO1
        //  思考别的解法 o(1) how
        // 找规律
        /**  1 -> 1
         *   2 -> 2
         *   3 -> 3
         *   4 -> 4
         *   5 -> 5
         *   6 -> 6
         *   7 -> 7
         *   8 -> 8
         *   9 -> 9
         *   10 -> 1
         *   11 -> 2
         *   12 -> 3
         *    ...
         *   9 个数一个循环, 
         * **/
        if (num == 0) {
            return 0;
        }
        int ans = num % 9;
        if (ans != 0) {
            return ans;
        }
        return 9;
        #endif  //  MACRO
    }
};
// @lc code=end

