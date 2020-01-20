/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 *
 * https://leetcode-cn.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (48.38%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    22.3K
 * Total Submissions: 46K
 * Testcase Example:  '6'
 *
 * 编写一个程序判断给定的数是否为丑数。
 * 
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 
 * 示例 1:
 * 
 * 输入: 6
 * 输出: true
 * 解释: 6 = 2 × 3
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: true
 * 解释: 8 = 2 × 2 × 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: 14
 * 输出: false 
 * 解释: 14 不是丑数，因为它包含了另外一个质因数 7。
 * 
 * 说明：
 * 
 * 
 * 1 是丑数。
 * 输入不会超过 32 位有符号整数的范围: [−2^31,  2^31 − 1]。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPrimeNumber(int n) {
        int sqt = sqrt(n);
        if (sqt * sqt == n) {
            return false;
        }
        for (int i = 2; i <= sqt; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool isUgly(int num) {
        // 边界
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        // 其他情况
        while (num % 30 == 0) {
            num /= 30;
        }
        while (num % 15 == 0) {
            num /= 15;
        }
        while (num % 10 == 0) {
            num /= 10;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 2 == 0) {
            num /= 2;
        }
        return num == 1;
    }
};
// @lc code=end

