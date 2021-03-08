/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
 public:
    // int gcd(int a, int b) {
    //     if (a < b) {
    //         return gcd(b, a);
    //     }
    //     while (b != 0) {
    //         int d = a % b;
    //         a = b;
    //         b = d;
    //     }
    //     return a;
    // }

    string gcdOfStrings1(string str1, string str2) {
        int i = 0, j = 0;
        int gc = gcd(str1.size(), str2.size());
        while (i < str1.size() && j < str2.size()) {
            if (str1[i++] != str2[j++]) {
                return "";
            }
            if (i == str1.size() && j == str2.size()) {
                return str1.substr(0, gc);
            }
            if (i == str1.size()) {
                i = 0;
            } else if (j == str2.size()) {
                j = 0;
            }
        }
        return "";
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int gc = gcd(str1.size(), str2.size());
        return str2.substr(0, gc);
    }
};
// @lc code=end

int main() {
    string s = "ABABAB";
    string ss = "AB";
    cout << Solution{}.gcdOfStrings(s, ss);
}
