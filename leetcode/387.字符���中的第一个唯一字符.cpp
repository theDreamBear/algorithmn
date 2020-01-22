/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (42.19%)
 * Likes:    171
 * Dislikes: 0
 * Total Accepted:    56.8K
 * Total Submissions: 133.1K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0) {
            return -1;
        }
        if (s.size() == 1) {
            return 0;
        }
        int hashmap[26];
        memset(hashmap, 0, 26 * sizeof(int));
        for (int i = 0; i < s.size(); ++i) {
            ++hashmap[s[i] - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (hashmap[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

