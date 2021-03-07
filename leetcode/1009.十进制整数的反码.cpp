/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement1(int N) {
        int bitwidth = 1;
        for (int i = 31; i >= 0; --i) {
            if (((N >> i) & 0x1) == 1) {
                bitwidth = i + 1;
                break;
            }
        }
        return (1 << bitwidth) - 1 - N;
    }

    int bitwiseComplement(int N) {
        bool start = false;
        for (int i = 31; i >= 0; --i) {
            if ((N >> i) & 0x1) {
                start = true;
            }
            if (start) {
                N ^= (0x1 << i);
            }
        }
        return !start ? 1 : N;
    }
};
// @lc code=end

