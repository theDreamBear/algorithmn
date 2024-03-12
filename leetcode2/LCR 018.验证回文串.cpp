/*
 * @lc app=leetcode.cn id=LCR 018 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 018] 验证回文串
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
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j and !isalnum(s[i])) {
                ++i;
            }
            if (i == j) {
                return true;
            }
            while (i < j and !isalnum(s[j])) {
                --j;
            }
            if (i == j) {
                return true;
            }
            if (s[i] != s[j]) {
                if (isdigit(s[i]) or isdigit(s[j])) {
                    return false;
                }
                if (::tolower(s[i]) != ::tolower(s[j])) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

 */

