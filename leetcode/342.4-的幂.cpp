/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (47.05%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 36.7K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour1(int num) {
        if ( num <= 0) {
            return false;
        }
        //  wrong 4 不是质数, 2 和 3 都可以用类似方法
        //  int x = pow(4, 15);
        //  return x % num == 0;
        if (num == 1) {
            return true;
        }
        // 1. 直接除法
        // 2. 数学法
        /**
         *  n = 4 ** i => i = log4(n) => i == 整数, 返回 true
         * 
         * 
         * ***/
        double x = log10(num) / log10(4);
        int ifloor = floor(x);
        int iceil = ceil(x);
        double p = pow(10, -15);
        if (x - ifloor <= p || iceil - x <= p) {
            return true;
        }
        return false;
    }

    /**
     *  num 是 4的幂, 那么 sqrt(num) 是 2的幂
     * 
     * 
     * **/
    bool isPowerOfFour2(int num) {
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        if (num < 4) {
            return false;
        }
        if ((num & num - 1) != 0) {
            return false;
        }
        // todo
        int z = sqrt(num);
        if (z * z != num) {
            return false;
        }
        return true;
    }

    /** 数学运算
     *    n = 2 ** (a), 先判断 n 是否为 2 的幂
     *    若 a =2k 或 2k + 1, k 为奇数
     *     a = 2k,  时 , 2 ** (2k) = 4 ** k, (3 + 1) ** k % 3 == 1
     *     a = 2k + 1  2 ** (2k + 1) = 2 * 4 ** k , 2 * 4 ** k % 3  = 2;
     * **/

    bool isPowerOfFour3(int num) {
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        if (num < 4) {
            return false;
        }
        if ((num & num - 1) != 0) {
            return false;
        }
        return num % 3 == 1;
    }

    /**
     *  位运算, 4 的幂的特点是 1 在奇数次位且为偶数
     * 
     * 
     * ***/
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        if (num < 4) {
            return false;
        }
        return ((num & (num - 1)) == 0) && ((num & 0x55555555) != 0);
    }
};
// @lc code=end

