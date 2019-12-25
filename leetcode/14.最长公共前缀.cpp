/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.54%)
 * Likes:    809
 * Dislikes: 0
 * Total Accepted:    163.4K
 * Total Submissions: 459.3K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        int index = 0;
        if (strs[0].size() == 0) {
            return "";
        }
        // import
        // char* 以\0 为结束符
        char buffer[strs[0].size() + 1];
        memset(buffer, '\0', sizeof(buffer));
        bool ok = true;
        for (; index < strs[0].size(); ++index) {
            if (!ok) {
                break;
            }
            char c = strs[0][index];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].size() <= index || strs[i][index] != c) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                buffer[index] = c;
            }
        }
        cout << index << ":" << endl;
        // for (size_t i = 0; i < sizeof(buffer); i++)
        // {
        //     cout << buffer[i] << endl;
        // }
        if (index == 0) {
            return "";
        }
        const char* st = buffer;
        //cout << st << ":" << sizeof(buffer) << endl;
        return st;
    }
};
// @lc code=end

int main () {
    Solution s;
    vector<string> vec = {"c", "c"};
    s.longestCommonPrefix(vec);
}
