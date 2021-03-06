/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (46.81%)
 * Likes:    150
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 52.8K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     *  审题
     * **/
    bool isIsomorphic(string s, string t) {
        char map[300];
        char hash[300];
        memset(map, 0, 300);
        memset(hash, 0, 300);
        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i]] != 0) {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            } else {
                char c = s[i];
                map[c] = t[i];
                if (hash[t[i]] != 0 && hash[t[i]] != s[i]) {
                    return false;
                }
                hash[t[i]] = s[i];
            }
        }
        return true;
    }
};
// @lc code=end

