/*
 * @lc app=leetcode.cn id=3083 lang=cpp
 * @lcpr version=30204
 *
 * [3083] 字符串及其反转中是否存在同一子字符串
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
    bool isSubstringPresent(string s) {
        string t = s;
        ranges::reverse(t);
        for (int i = 0; i + 1 < s.size(); i++) {
            if (t.find(s.substr(i, 2)) != string::npos) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "abcba"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n
// @lcpr case=end

 */

