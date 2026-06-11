/*
 * @lc app=leetcode.cn id=389 lang=cpp
 * @lcpr version=30204
 *
 * [389] 找不同
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
    char findTheDifference1(string s, string t) {
        ranges::sort(s);
        ranges::sort(t);
        int i = 0, j = 0;
        for (; i < s.size() and j < t.size(); i++, j++) {
            if (s[i] != t[j]) return t[j];
        }
        return t[j];
    }

    char findTheDifference(string s, string t) {
        int x = 0;
        for (auto c: s) x ^= c;
        for (auto c: t) x ^= c;
        return x;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcd"\n"abcde"\n
// @lcpr case=end

// @lcpr case=start
// ""\n"y"\n
// @lcpr case=end

 */

