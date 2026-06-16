/*
 * @lc app=leetcode.cn id=3612 lang=cpp
 * @lcpr version=30204
 *
 * [3612] 用特殊操作处理字符串 I
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
    string processStr(string s) {
        string res;

        auto push = [&](char ch) {
            res.push_back(ch);
        };

        auto pop = [&]() {
            if (res.size()) {
                res.pop_back();
            }
        };

        auto cp = [&]() {
            res += res;
        };

        auto rev = [&]() {
            reverse(res.begin(), res.end());
        };

        for (auto ch: s) {
            if (ch == '*') {
                pop();
            } else if (ch == '#') {
                cp();
            } else if (ch == '%') {
                rev();
            } else {
                push(ch);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a#b%*"\n
// @lcpr case=end

// @lcpr case=start
// "z*#"\n
// @lcpr case=end

 */

