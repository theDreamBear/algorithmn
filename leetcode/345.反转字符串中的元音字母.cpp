/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (48.40%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    22.1K
 * Total Submissions: 45.3K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

// @lc code=start
class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        string ans = s;
        if (ans.size() <= 1) {
            return ans;
        }
        int i = 0, j = ans.size() - 1;
        for (; i < j; ++i, --j) {
            while (i < j && !isVowel(ans[i])) {
                ++i;
            }
            while (i < j && !isVowel(ans[j])) {
                --j;
            }
            if (i < j) {
                ans[i] ^= ans[j];
                ans[j] ^= ans[i];
                ans[i] ^= ans[j];
            }
        }
        return ans;
    }
};
// @lc code=end

