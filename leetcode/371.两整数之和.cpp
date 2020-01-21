/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (53.06%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    20.8K
 * Total Submissions: 38.9K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     *  * 负数不支持左移
     * 
     * **/
    int getSum(int a, int b) {
        // 处理负数
        while (a != 0) {
            int c = (unsigned int)(a & b) << 1;
            b = (a ^ b);
            a = c;
        }
        return b;
    }
};
// @lc code=end

