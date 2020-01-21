/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 *
 * https://leetcode-cn.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (45.71%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 72.7K
 * Testcase Example:  '27'
 *
 * 给定一个整数，写一个函数来判断它是否是 3 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 27
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: 9
 * 输出: true
 * 
 * 示例 4:
 * 
 * 输入: 45
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */
#include<math.h>

// @lc code=start
class Solution {
public:
/**
 *  官方题可以多看看
 * 
 * 
 * 
 * **/

/**
 * 
 *  递归
 * 
 * 
 * **/
    bool isPowerOfThree1(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        if (n % 3 != 0) {
            return false;
        }
        return isPowerOfThree(n / 3);
    }

/**
 *  循环
 * 
 * **/
    bool isPowerOfThree2(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        // 3的幂的位数优化, 直接排除
        int tail = n % 10;
        if (tail != 1 && tail != 3 && tail != 9 && tail != 7) {
            return false;
        }
        while (n != 1 && n % 3 == 0) {
            n = n / 3;
        }
        if (n == 1) {
            return true;
        }
        return false;
    }

/**
 *  3. 整数限制法   重点
 *    最大的 3 的幂可以整除 n, 不能整除就不是 3的幂
 * 
 * 
 * 
 * 
 * 
 * **/
    bool isPowerOfThree3(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        return (int)pow(3, 19) % n == 0; 
    }

    /**
     *  3. 3进制, 最低位为 0
     * 
     * 
     * **/
    bool isPowerOfThree4(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        // 没啥意思不实现了
        return false;
    }

    /**
     * 
     *  数学  n = 3** i
     *     i = log3(n)  =>  log10(n) / log10(3) == 整数  可能因为精度原因, 需要特殊处理
     * **/
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        double x = log(n) / log(3);
        int ifloor = floor(x);
        int iceil = ceil(x);
        double p = pow(10, -10);
        if (x - ifloor < p || iceil - x < p) {
            return true;
        }
        return false;
    }
};
// @lc code=end

