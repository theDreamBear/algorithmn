/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (57.47%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    67.9K
 * Total Submissions: 117.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        //  #ifdef DEBUG  // hash 方法
        int ah[26];
        memset(ah, 0, 26 * sizeof(int));
        for (int i = 0; i < s.size(); ++i) {
            ++ah[s[i] - 'a'];
            --ah[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (ah[i] != 0) {
                return false;
            }
        }
        return true;
       //  #endif  //  DEBUG

        // 异或 + 加法 不行
        #ifdef DEBUG1
        if (s.size() == 0) {
            return true;
        }
        int ans = s[0];
        long long add = s[0];
        for (int i = 1; i < s.size(); ++i) {
            ans ^= s[i];
            add += s[i];
        }
        for (int i = 0; i < t.size(); ++i) {
            ans ^= t[i];
            add -= t[i];
        }
        return ans == 0 && add == 0;
        #endif  //  DEBUG1
    }
};
// @lc code=end

