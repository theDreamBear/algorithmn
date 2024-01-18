/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        if (chars.size() == 1) {
            return 1;
        }
        int ct = 1;
        char ch = chars[0];
        int pos = 0;
        for (int i = 1; i < chars.size(); i++) {
            if (ch == chars[i]) {
                ct++;
            } else {
                ans += 1;
                chars[pos++] = ch;
                if (ct > 1) {
                    auto str = to_string(ct);
                    ans += str.size();
                    for (int j = 0; j < str.size(); j++) {
                        chars[pos++] = str[j];
                    }
                }
                ct = 1;
                ch = chars[i];
            }
        }
        ans += 1;
        chars[pos++] = ch;
        if (ct > 1) {
            auto str = to_string(ct);
            ans += str.size();
            for (int j = 0; j < str.size(); j++) {
                chars[pos++] = str[j];
            }
        }
        chars.erase(chars.begin() + pos, chars.end());
        return ans;
    }
};
// @lc code=end

