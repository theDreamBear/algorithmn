/*
 * @lc app=leetcode.cn id=LCR 016 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 016] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        int ah[300]{0};
        int ans = 0;
        int left = 0, right = 0, ct = 0;
        for (; right < s.size(); right++) {
            if (++ah[s[right]] > 1) {
                while (left <= right and ah[s[right]] > 1) {
                    --ah[s[left]];
                    ++left;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

