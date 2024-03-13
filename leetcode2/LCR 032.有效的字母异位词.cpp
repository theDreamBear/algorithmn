/*
 * @lc app=leetcode.cn id=LCR 032 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 032] 有效的字母异位词
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
    bool isAnagram1(string s, string t) {
        if (s == t) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram(string s, string t) {
        if (s == t || s.size() != t.size()) {
            return false;
        }
        int ct[26]{0}, left = 0;
        for (auto v : s) {
            if (++ct[v - 'a'] == 1) {
                ++left;
            }
        }
        for (auto v : t) {
            if (--ct[v - 'a'] == 0) {
                --left;
            }
        }
        return left == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

 */

