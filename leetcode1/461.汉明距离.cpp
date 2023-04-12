/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
// & 优先级 > ^
// @lc code=start
class Solution {
public:
    int hammingDistance1(int x, int y) {
        int ct = 0;
        for (int i = 0; i < 32; i++) {
            if (((x >> i) ^ (y >> i)) & 0x1) {
                ct++;
            }
        }
        return ct;
    }

    int clz(int x) {
        if (x == 0) {
            return -1;
        }
        return 32 - __builtin_clz(x);
    }

    int hammingDistance(int x, int y) {
//        int fx = clz(x);
//        int fy = clz(y);
//        if (fx == -1 && fy == -1) {
//            return 0;
//        }
//        if (fx == -1 || fy == -1) {
//            if (fx == -1) {
//                return __builtin_popcount(y);
//            }
//            return __builtin_popcount(x);
//        }
//        int upperLimit = (1 << max(fx, fy)) - 1;
//        int v = (x ^ y) & upperLimit;
//        return __builtin_popcount(v);
        return __builtin_popcount((x ^ y) & (-1));
    }
};
// @lc code=end

