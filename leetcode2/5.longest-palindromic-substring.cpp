/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30116
 *
 * [5] 最长回文子串
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome_violatile(string s) {
        int len = 0;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (isPalindrome(s, i, j) and j - i + 1 > len) {
                    len = j - i + 1;
                    ans = s.substr(i, len);
                }
            }
        }
        return ans;
    }

    //
    string longestPalindrome_1(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int len = 0;
        string ans;

        auto check = [&](int l, int r) {
            for (int d = 0; l - d >= 0 and r + d < s.size(); d++) {
                if (s[l - d] != s[r + d]) {
                    break;
                }
                dp[l - d][r + d] = 1;
                if (r - l + (d << 1) + 1 > len) {
                    len = r - l + (d << 1) + 1;
                    ans = s.substr(l - d, len);
                }
            }
        };
        for (int i = 0; i < s.size(); i++) {
            check(i, i);
            check(i, i + 1);
        }
        return ans;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int len = 0, left = 0;
        // 枚举尾部j
        for (int j = 0; j < s.size(); j++) {
            for (int i = 0; i <= j; i++) {
                dp[i][j] = s[i] == s[j];
                if (i + 1 <= j - 1) {
                    dp[i][j] &= dp[i + 1][j - 1];
                }
                if (dp[i][j] and j - i + 1 > len) {
                    len = j - i + 1;
                    left = i;
                }
            }
        }
        return s.substr(left, len);
    }

};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

