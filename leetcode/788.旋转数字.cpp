/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution {
public:
    int ah[10] = {1, 1, 1, 0, 0, 1, 1, 0, 1, 1};

    bool isGoodNumber(int val) {
        bool changed = false;
        while (val > 0) {
            int tail = val % 10;
            if (!ah[tail]) {
                return false;
            }
            if (tail == 2 || tail == 5 || tail == 6 || tail == 9) {
                changed = true;
            }
            val /= 10;
        }
        return changed;
    }

    int rotatedDigits(int N) {
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            if (isGoodNumber(i)) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

