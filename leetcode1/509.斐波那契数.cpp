/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int a = 0;
        int b = 1;
        while (n > 1) {
            int c = b;
            b = a + b;
            a = c;
            --n;
        }
        return b;
    }
};
// @lc code=end

