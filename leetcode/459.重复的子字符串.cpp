/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
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
    void rotate(string& s) {
        char temp = s[s.size() - 1];
        for (int i = s.size() - 2; i >= 0; --i) {
            s[i+ 1] = s[i];
        }
        s[0] = temp;
    }

    /*
        超时
    */
    bool repeatedSubstringPattern(string s) {
        string source = s;
        for (int i = 1; i < s.size(); ++i) {
            rotate(s);
            if (s == source) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    string s = "babbabbabbabbab";
    cout << Solution{}.repeatedSubstringPattern(s) << endl;
}

