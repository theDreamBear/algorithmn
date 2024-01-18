/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        vector<int> px(26);
        unsigned long long mask = 0;
        unsigned long long mask2 = 0;
        int ct = 0;
        for (auto ch: p) {
            if (++px[ch - 'a'] == 1) {
                ct++;
            }
            mask += (1ul << (ch - 'a'));
            mask2 += (1ul << (2 * (ch - 'a')));
        }
        vector<int> ans;
        unsigned long long now = 0;
        unsigned long long now2 = 0;
        int n = p.size();
        for (int i = 0; i + 1 < n; i++) {
            now += (1ul << (s[i] - 'a'));
            now2 += (1ul << (2 * (s[i] - 'a')));
        }
        for (int i = n - 1; i < s.size(); i++) {
            now += (1ul << (s[i] - 'a'));
            now2 += (1ul << (2 * (s[i] - 'a')));
            if (mask == now && mask2 == now2) {
                vector<int> sx = px;
                int left = ct;
                for (int j = i - n + 1; j <= i; j++) {
                    --sx[s[j] - 'a'];
                    if (sx[s[j] - 'a'] < 0) {
                        break;
                    }
                    if (sx[s[j] - 'a'] == 0) {
                        left--;
                    }
                }
                if (left == 0) {
                    ans.push_back(i - n + 1);
                }
            }
            now -= (1ul << (s[i - n + 1] - 'a'));
            now2 -= (1ul << (2 * (s[i - n + 1] - 'a')));
        }
        return ans;
    }
};
// @lc code=end

