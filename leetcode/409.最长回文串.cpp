/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
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
int ah[300];
class Solution {
public:
    int longestPalindrome(string s) {
        fill(begin(ah), end(ah), 0);
        for (auto c: s) {
            ++ah[c];
        }
        int ans = 0;
        bool exist = false;
        for (int i = 0; i < 300; ++i) {
            ans += ((ah[i] >> 1) << 1);
            if (!exist && ah[i] & 0x1) {
                exist = true;
            }
        }
        if (exist) {
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

int main() {
    string s = "abccccdd";
    cout << Solution{}.longestPalindrome(s);
}

