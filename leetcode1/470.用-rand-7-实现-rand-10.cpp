/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
/*    int rand7() {
        return 1;
    }*/

    int rand2() {
        int r = rand7();
        while (r >= 7) {
            r = rand7();
        }
        return r % 2;
    }

    int rand10() {
        int r = 11;
        do {
            r = rand7() + (rand2() ? 7 : 0);
        } while (r > 10);
        return r;
    }
};
// @lc code=end

