/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30114
 *
 * [242] 有效的字母异位词
 */


// @lcpr-template-start
#include <numeric>
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
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram2(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int ah[26] = {0};
        for (auto c : s) {
            ah[c - 'a']++;
        }
        for (auto c : t) {
            if (--ah[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        hash<char> h;
        bool left =  accumulate(s.begin(), s.end(), 0, [&](int l, int r) {
            return h(l) + h(r);
        }) == accumulate(t.begin(), t.end(), 0, [&](int l , int r) {
            return h(l) + h(r);
        });

        bool right =  accumulate(s.begin(), s.end(), 1, [&](int l, int r) {
            return l * h(r);
        }) == accumulate(t.begin(), t.end(), 1, [&](int l , char r) {
            return l * h(r);
        });
        return left and right;
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

 */

