/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
long long goodNumber(int n) {
    if (n <= 0) {
        return 1;
    }
    if (n == 1) {
        return 10;
    }
    int ans = 9;
    int left = 10;
    while (--n > 0 && --left > 0) {
        ans *= left;
    }
    return ans;
}

class Solution {
 public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)  {
            ans += goodNumber(i);
        }
        return ans;
    }
};
// @lc code=end

