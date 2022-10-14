/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        int upperLimit = (1 << n) - 1;
        function<void(int, int ,int)> backtrack = [&](int num, int ll, int rr) {
            if (num == upperLimit) {
                ++ans;
                return;
            }
            int mask = upperLimit & ~(ll | rr | num);
            while (mask > 0) {
                int v = mask & ~(mask - 1);
                backtrack(num ^ v, (ll ^ v) << 1, (rr ^ v) >> 1);
                mask ^= v;
            }
        };
        backtrack(0, 0, 0);
        return ans;
    }
};
// @lc code=end

