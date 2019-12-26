/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (53.68%)
 * Likes:    360
 * Dislikes: 0
 * Total Accepted:    64K
 * Total Submissions: 119.2K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
#include<string>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string getCount1(string s, int& index) {
        char c = s[index];
        ++index;
        int ct = 1;
        while(index < s.size() && c == s[index]) {
            ++ct;
            ++index;
        }
        return string(1, ct + '0') + c;
    }
    string countAndSay1(int n) {
        string res = "1";
        int index = 1;
        string s;
        // 注意判定条件
        for (; index < n; ++index) {
            int i = 0;
            for(; i < res.size();) {
                s += getCount1(res, i);
            }
            res = s;
            //cout << s << endl;
            s = "";
        }
        return res;
    }

    string countAndSay(int n) {
        string ans(1, '1');
        string temp;
        for (int index = 1; index < n; ++index) {
            int sz = ans.size();
            int i = 0;
            for(; i < sz; ) {
                char c = ans[i];
                ++i;
                int ct = 1;
                while (i < sz && ans[i] == c) {
                    ++ct;
                    ++i;
                }
                // string push_back 方法
                temp.push_back(ct + '0');
                temp.push_back(c);
            }
            ans = temp;
            temp = "";
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    for (int i = 1; i <= 5; ++i) {
        cout << s.countAndSay(i) << endl;
    }
}