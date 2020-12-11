/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0;
        int len = 0;
        for (int i = 0; i < s.size(); ++i) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            int nLen = (right - left - 1);
            if (nLen > len) {
                l = left + 1;
                len = nLen;
            }
        }
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                int left = i - 2;
                int right = i + 1;
                while (left >= 0 && right < s.size() && s[left] == s[right]) {
                    --left;
                    ++right;
                }
                int nLen = (right - left - 1);
                if (nLen > len) {
                    l = left + 1;
                    len = nLen;
                }
            }
        }
        return s.substr(l, len);
    }
};
// @lc code=end

int main() {
    cout << Solution{}.longestPalindrome("babad");
}
