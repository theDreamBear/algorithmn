/*
 * @lc app=leetcode.cn id=LCR 019 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 019] 验证回文串 II
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
    bool validPalindrome(const string& s, int low, int high) {
        for (; low < high and s[low] == s[high]; low++, high--);
        return low >= high;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        for (; i < j and s[i] == s[j]; i++, j--);
        if (i >= j) {
            return true;
        }
        // 删除i
        // 删除j
        return validPalindrome(s, i + 1, j) || validPalindrome(s, i, j - 1);
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

