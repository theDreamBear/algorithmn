/*
 * @lc app=leetcode.cn id=859 lang=cpp
 * @lcpr version=30204
 *
 * [859] 亲密字符串
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
    bool buddyStrings1(string s, string goal) {
        if (s == goal) {
            int cnt[26]{};
            for (auto ch: s) {
                if (++cnt[ch - 'a'] == 2) return true;
            }
            return false;
        }
        int et = 0;
        string x = s, y = goal;
        ranges::sort(x);
        ranges::sort(y);
        if (x != y) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                et++;
            }
        }
        return et == 2;
    }

    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s == goal) {
            int cnt[26]{};
            for (auto ch: s) {
                if (++cnt[ch - 'a'] == 2) return true;
            }
            return false;
        }
        int et = 0;
        int ft = -1, st = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (ft == -1) {
                    ft = i;
                } else if (st == -1) {
                    st = i;
                } else {
                    return false;
                }
            }
        }
        return !(ft == -1 and st == -1) and (ft != -1 and st != -1 and s[ft] == goal[st] and s[st] == goal[ft]);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ab"\n"ba"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aa"\n
// @lcpr case=end

 */

