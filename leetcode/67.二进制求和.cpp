/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (51.63%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    54.1K
 * Total Submissions: 104.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
#include <iostream>
#include<string>
#include<string.h>
using namespace std;
// @lc code=start
class Solution {
public:
    /**
     * 
     *  '0-9' 和数字0-9 之间的转换要小心
     * 
     * **/
    string addBinary(string a, string b) {
        //cout << a << " " << b << endl;
        int sz = max(a.size(), b.size()) + 2;
        char ah[sz];
        memset(ah, '\0', sz);
        //int index = 0;
        int as = a.size() - 1;
        int bs = b.size() - 1;
        int over = 0;
        sz -= 2;
        for (; sz >= 0; --sz) {
            if (as >= 0 && bs >= 0) {
                ah[sz] = a[as] - '0' + b[bs] + over;
                over = 0;
                if (ah[sz] >= '2') {
                    over = 1;
                    ah[sz] -= 2;
                }
                --as;
                --bs;
                cout << ah[sz] << " ";
                cout << over << endl;
            } else if (as >= 0) {
                //cout <<sz << endl;
                ah[sz] = a[as] + over;
                over = 0;
                //cout << ah[sz] << endl;
                --as;
                if (ah[sz] == '2') {
                    ah[sz] = '0';
                    over = 1;
                    //cout << over << " " << ah[sz] << endl;
                }
            } else if (bs >= 0) {
                ah[sz] = b[bs] + over;
                cout << ah[sz] << " " << endl;
                over = 0;
                --bs;
                if (ah[sz] == '2') {
                    ah[sz] = '0';
                    over = 1;
                } 
            } else if (over == 1) {
                ah[0] = '1';
                break;
            }
            //cout << ah[sz] << " ";
        }
        if (over == 1) {
            ah[0] = '1';
        }
        if (ah[0] == 0) {
            return ah + 1;
        }
        return ah;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.addBinary("100", "110010") << "***";
}