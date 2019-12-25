/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.26%)
 * Likes:    1276
 * Dislikes: 0
 * Total Accepted:    172.9K
 * Total Submissions: 429.4K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include<stack>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // 边界 字符为空
        if (s.size() == 0) {
            return true;
        }
        stack<char> bracketStack;
        for (int index = 0; index < s.size(); index++) {
            char c = s[index];
            if ('[' == c || '(' == c || '{' == c) {
                bracketStack.push(c);
                continue;
            }
            char cmpChar;
            switch (c) {
                case ')' : {
                    cmpChar = '(';
                    break;
                }
                case ']' :
                    cmpChar = '[';
                    break;
                case '}' :
                    cmpChar = '{';
                    break;
                default:
                    break;
            }
            if (bracketStack.empty() || bracketStack.top() != cmpChar) {
                return false;
            }
            bracketStack.pop();
        }
        return bracketStack.empty();
    }
};
// @lc code=end

