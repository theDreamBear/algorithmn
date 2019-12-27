/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (37.27%)
 * Likes:    274
 * Dislikes: 0
 * Total Accepted:    80.7K
 * Total Submissions: 216.3K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        #ifdef DEBUG
        // 若 x 为整数最大值, 则 i * i 可能为越界
        long long i = 0;
        for (; i * i <= x; ++i);
        if (i * i == x) {
            return i;
        }
        return i - 1;
        #endif // DEBUG

        // 当 x为最大int时, (i +1 ) * (i + 1) > MaxInt, 会超出int范围导致 ans 为一个负值 
        long long i = 0;
        long long ans = 0;
        for (; i <= x; ++i) {
            ans = i * i;
            if (ans > x) {
                return --i;
            }
            if (ans == x) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

int main() {
    long long i = 46341;
    long long x = i * i;
    cout << x;
}