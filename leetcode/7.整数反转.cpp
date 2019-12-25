/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.32%)
 * Likes:    1541
 * Dislikes: 0
 * Total Accepted:    241.1K
 * Total Submissions: 723.5K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        // 有符号数负数范围大于正数
        long long v = x;
        long long ans = 0;
        long long maxInt = 0x7fffffff;
        if (v < 0) {
            sign = -1;
            v = -1 * v;
        }
        while(v) {
            int low = v % 10;
            v = v / 10;
            ans = ans * 10 + low;
        }
        // 正数特殊情况
        if (sign == 1 && ans > maxInt) {
            return 0;
        }
        // 负数特殊情况
        if (sign == -1 && ans > maxInt + 1) {
            return 0;
        }
        return sign * ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.reverse(-2147483648);
}