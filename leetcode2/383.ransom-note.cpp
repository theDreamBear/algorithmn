/*
 * @lc app=leetcode.cn id=383 lang=cpp
 * @lcpr version=30114
 *
 * [383] 赎金信
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
    // 时间复杂度O(m  + n), 空间复杂度O(1)
    bool canConstruct(string ransomNote, string magazine) {
        int set[26]{0};
        for (auto c : magazine) {
            set[c - 'a']++;
        }
        for (auto c : ransomNote) {
            if (--set[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aab"\n
// @lcpr case=end

 */

