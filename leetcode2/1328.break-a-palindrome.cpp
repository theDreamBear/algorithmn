/*
 * @lc app=leetcode.cn id=1328 lang=cpp
 * @lcpr version=30204
 *
 * [1328] 破坏回文串
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
    string breakPalindrome(string s) {
        int n = s.size();
        if (n == 1) return "";
        int i = 0;
        while (i < n and s[i] == 'a') i++;
        if (i == n) s[n - 1] = 'b';
        else {
            s[i] = 'a';
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abccba"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

