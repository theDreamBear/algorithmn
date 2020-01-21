/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.69%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    21.4K
 * Total Submissions: 49.9K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare1(int num) {
        #define f1
        #ifdef f1
        long long i = 1;
        for (; i * i < num; ++i);
        if (i * i == num) {
            return true;
        }
        return false;
        #endif  //  f1
    }

    /**
     * 
     * 二分查找
     * 
     * **/
    bool isPerfectSquare2(int num) {
        if (num == 1) {
            return true;
        }
        long long low = 1, high = num;
        while (low + 1 < high) {
            long long mid = low + (high - low) / 2;
            long long temp = mid * mid;
            if (temp > num) {
                high = mid;
            } else if (temp <= num) {
                low = mid;
            }
        }
        if (low * low == num) {
            return true;
        }
        if (high * high == num) {
            return true;
        }
        return false;
    }

    /**
     *  牛顿迭代法
     * 
     * 
     * 
     * **/

    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        long long mid = num / 2;
        while (mid * mid > num) {
            mid = (mid + num / mid) / 2;
        }
        return mid * mid == num;
    }
};
// @lc code=end

