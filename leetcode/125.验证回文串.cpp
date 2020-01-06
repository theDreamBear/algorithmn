/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (41.72%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    69.9K
 * Total Submissions: 166.9K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
#include <iostream>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    char hashMap[255];
    bool isSuitable(char& c) {
        #ifdef DEBUG
        if (c >= '0' && c  <= '9') {
            return true;
        }
        c |= 0x20;
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        return false;
        #endif // DEBUG

        //cout << c << endl;
        if (hashMap[c] == '1' || hashMap[c |= 0x20] == '1') {
            //cout << c << endl;
            return true;
        }
        return false;
    }

    void initHashMap() {
        memset(hashMap, 0, 255);
        for(char c = '0'; c <= '9'; ++c) {
            hashMap[c] = '1';
        }
        for(char c = 'a'; c <= 'z'; ++c) {
            hashMap[c] = '1';
        }
    }
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        initHashMap();
        int low = 0, high = s.size() - 1;
        while(low <= high) {
            // left
            while(low <= high && !isSuitable(s[low])) {
                ++low;
            }
            // right
            while(low <= high && !isSuitable(s[high])) {
                --high;
            }
            // compare
            if (low <= high) {
                if (s[low] != s[high]) {
                    return false;
                }
                //cout << "left: " << s[low] << endl;
                //cout << "right: " << s[high] << endl;
            }
            ++low;
            --high;
        }
        return true;
    }
};
// @lc code=end

int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution so;
    cout << so.isPalindrome(s);
}
