/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode-cn.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (51.09%)
 * Likes:    66
 * Dislikes: 0
 * Total Accepted:    15.2K
 * Total Submissions: 29.5K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给定一个赎金信 (ransom)
 * 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回
 * true ；否则返回 false。
 * 
 * (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
 * 
 * 注意：
 * 
 * 你可以假设两个字符串均只含有小写字母。
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) {
            return false;
        }
        int hashmap[26];
        memset(hashmap, 0, 26 * 4);
        for (int i = 0; i < magazine.size(); ++i) {
            ++hashmap[magazine[i] - 'a'];
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            if (--hashmap[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

