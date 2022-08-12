/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hmap(300);
        int start = 0, end = 0;
        int max_len = 0;
        while (end < s.size()) {
            while (end < s.size() && hmap[s[end]] == 0) {
                ++hmap[s[end]];
                ++end;
            }
            max_len = max(max_len, end - start);
            // 收缩滑动窗口
            if (end < s.size()) {
                char ch = s[end];
                while (start <= end && hmap[ch] > 0) {
                    --hmap[s[start]];
                    ++start;
                }
            }
        }
        max_len = max(max_len, end - start);
        return max_len;
    }
};
// @lc code=end

