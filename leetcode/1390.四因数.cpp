/*
 * @lc app=leetcode.cn id=1390 lang=cpp
 *
 * [1390] 四因数
 */

// @lc code=start
class Solution {
public:
    int sumFourDivisorsHelper(int value) {
        if (value == 1) {
            return 0;
        }
        int ans = 1 + value;
        int dct = 2;
        for (int j = 2; j <= sqrt(value); ++j) {
            if (value % j == 0) {
                if (++dct > 4) {
                    return 0;
                }
                ans += j;
                if (j * j != value) {
                    if (++dct > 4) {
                        return 0;
                    }
                    ans += value / j;
                }
            }
        }
        if (dct == 4) {
            return ans;
        }
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (auto v : nums) {
            ans += sumFourDivisorsHelper(v);
        }
        return ans;
    }
};
// @lc code=end

