/*
 * @lc app=leetcode.cn id=2840 lang=cpp
 * @lcpr version=30204
 *
 * [2840] 判断通过操作能否让字符串相等 II
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
    bool checkStrings(string s1, string s2) {
        // acb cba
        // bda adb
        auto check = [&](int idx) {
            string l, r;
            for (int i = idx; i < s1.size(); i+= 2) {
                l.push_back(s1[i]);
                r.push_back(s2[i]);
            }
            ranges::sort(l);
            ranges::sort(r);
            return l == r;
        };
        return check(0) and check(1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcdba"\n"cabdab"\n
// @lcpr case=end

// @lcpr case=start
// "abe"\n"bea"\n
// @lcpr case=end

 */

