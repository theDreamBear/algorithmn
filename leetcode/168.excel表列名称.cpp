/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (35.91%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 47.9K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
#include<iostream>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    const char* key = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string convertToTitle(int n) {
        //stack<int> st;
        string ans;
        while(n != 0) {
            int x = n % 26;
            if (x == 0) {
                x = 26;
            }
            n = (n - x) / 26;
            ans.push_back(key[x]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.convertToTitle(12);
}