/*
 * @lc app=leetcode.cn id=LCR 169 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 169] 招式拆解 II
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
    char dismantlingAction(string arr) {
        int ct[26] = {0};
        for (auto ch : arr) {
            ct[ch - 'a']++;
        }
        for (auto ch : arr) {
            if (ct[ch - 'a'] == 1) {
                return ch;
            }
        }
        return ' ';
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbccdeff"\n
// @lcpr case=end

// @lcpr case=start
// "ccdd"\n
// @lcpr case=end

 */

