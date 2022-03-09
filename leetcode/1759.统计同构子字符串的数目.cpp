/*
 * @lc app=leetcode.cn id=1759 lang=cpp
 *
 * [1759] 统计同构子字符串的数目
 */

// @lc code=start
constexpr static int Mod = 1e9 + 7;
class Solution {
 public:

    long long HomogenousLen(long long n) {
        return ((1 + n) * n)  >> 1;
    }

    int countHomogenous(string s) {
        long long ans = 0;
        char last = '#';
        int sz = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last == '#' || s[i] == last) {
                last = s[i];
                ++sz;
                continue;
            }
            ans += HomogenousLen(sz);
            last = s[i];
            sz = 1;
        }
        ans += HomogenousLen(sz);
        return ans % (Mod);
    }
};
// @lc code=end

