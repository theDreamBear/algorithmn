/*
 * @lc app=leetcode.cn id=680 lang=cpp
 * @lcpr version=30204
 *
 * [680] 验证回文串 II
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        auto isP = [&](int l, int r) {
            for (; l < r; l++, r--) {
                if (s[l] != s[r]) return false;
            }
            return true;
        };
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return isP(i + 1, j) or isP(i, j - 1);
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

