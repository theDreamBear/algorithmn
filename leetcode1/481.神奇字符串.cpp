/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int idx = 2;
        int val = 1;
        while (s.size() <= n) {
            int t = s[idx] - '0';
            s.push_back(val + '0');
            if (t == 2) {
                s.push_back(val + '0');
            }
            val = 3 - val;
            idx++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

