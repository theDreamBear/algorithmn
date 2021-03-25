/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
     int upperlimit = 0;

    void test(int now, int left, int right, int& sum) {
        if (now == upperlimit) {
            ++sum;
            return;
        }
        if (now != upperlimit) {
            int pos  = upperlimit &  ~ (now | left | right);
            while (pos) {
                int  p = pos & -pos;
                test(now ^ p, (left ^ p) << 1, (right ^ p) >> 1, sum);
                pos -= p;
            }
        }
    }

    int totalNQueens(int n) {
        upperlimit = (1 << n) - 1;
        int now = 0, left = 0, right = 0, sum = 0;
        test(now, left, right, sum);
        return sum;
    }
};
// @lc code=end

