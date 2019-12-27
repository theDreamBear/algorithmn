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
     *   redo
     * **/
    void init(char* arr, int n) {
        memset(arr, '0', n);
        arr[n - 1] = '\0';
    }

    void padding(char* arr, string& source, int n) {
        int startIndex = n - 1 - source.size();
        for (int i = 0; i <= source.size() - 1; ++i, ++startIndex) {
            arr[startIndex] = source[i];
        }
    }

    void add(char* des, const char* source, int n) {
        int index = n - 2;
        int over = 0;
        for (; index >= 0; --index) {
            des[index] += (source[index] - '0' + over);
            if (des[index] >= '2') {
                over = 1;
                des[index] -= 2;
            } else {
                over = 0;
            }
        }
    }

    string judge(const char* source) {
        if (source[0] == '0') {
            return source + 1; 
        }
        return source;
    }
    string addBinary1(string a, string b) {
        // 预处理, 先对齐
        int ansSize = max(a.size(), b.size()) + 1 + 1;
        char aChar[ansSize], bChar[ansSize];
        
        // 初始化
        init(aChar, ansSize);
        init(bChar, ansSize);

        // 对齐填充
        padding(aChar, a, ansSize);
        padding(bChar, b, ansSize);

        // 计算
        add(aChar, bChar, ansSize);
        
        return judge(aChar);
    }

    string addBinary(string a, string b) {
        int ansSize = max(a.size(), b.size()) + 2;
        char ans[ansSize];
        memset(ans, '0', ansSize);
        ans[ansSize - 1] = '\0';
        int index = ansSize - 2;
        int aIndex = a.size() - 1;
        int bIndex = b.size() - 1;
        int over = 0;
        while(aIndex >= 0 || bIndex >= 0) {
            if (aIndex >= 0 && bIndex >= 0) {
                ans[index] = a[aIndex] - '0' + b[bIndex] + over;
                over = 0;
                if (ans[index] >= '2') {
                    over = 1;
                    ans[index] -= 2;
                }
                --aIndex;
                --bIndex;
                --index;
            } else if (aIndex >= 0) {
                ans[index] = a[aIndex] + over;
                over = 0;
                if (ans[index] >= '2') {
                    over = 1;
                    ans[index] -= 2;
                }
                --aIndex;
                --index;
            } else if (bIndex >= 0) {
                ans[index] = b[bIndex] + over;
                over = 0;
                if (ans[index] >= '2') {
                    ans[index] -= 2;
                    over = 1;
                }
                --bIndex;
                --index;
            }
        }
        if (over == 1) {
            ans[0] += 1;
        }
        if (ans[0] == '0') {
            return ans + 1;
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    string a("100");
    string b("110010");
    cout << a.size() << " " << b.size() << endl;
    cout << s.addBinary(a, b) << endl;
}