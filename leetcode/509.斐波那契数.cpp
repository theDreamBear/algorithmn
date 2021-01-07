/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib_bad(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fib_bad(n - 1) + fib_bad(n - 2);
    }

   int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int prepre = 0;
        int pre = 1;
        for (int i = 2; i <= n; ++i) {
            int x  = pre + prepre;
            prepre = pre;
            pre = x;
        }
        return pre;
    }

};
// @lc code=end

