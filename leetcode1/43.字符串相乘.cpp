/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
   public:
    string multiply(string num1, string num2) {
        int m = (int)num1.size();
        int n = (int)num2.size();
        if (0 == m || n == 0) {
            return "0";
        }
        string ans(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n - 1; j >= 0; j--) {
                int val = (num1[i] - '0') * (num2[j] - '0') + carry;
                ans[i + j + 1] += val;
                carry = ans[i + j + 1] / 10;
                ans[i + j + 1] = ans[i + j + 1] % 10;
            }
            ans[i] += carry;
        }
        for (int i = 0; i < m + n; i++) {
            ans[i] += '0';
        }
        int i = 0;
        while (i < m + n && ans[i] == '0') {
            i++;
        }
        // 全部都是0
        if (i == m + n) {
            return "0";
        }
        return ans.substr(i);
    }
};
// @lc code=end
