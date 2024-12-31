/*
 * @lc app=leetcode.cn id=面试题 01.09 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 01.09] 字符串轮转
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
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int i = 0, j = 0;
        return (s1 + s1).find(s2) != string::npos;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "waterbottle"\n"erbottlewat"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aba"\n
// @lcpr case=end

 */

