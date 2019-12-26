/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (31.81%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    58.3K
 * Total Submissions: 183K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int sz = s.size() - 1;
        while(s[sz] == ' ') {
            --sz;
        }
        // 序号要大于 0
        while(sz >= 0 && s[sz--] != ' ') {
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

