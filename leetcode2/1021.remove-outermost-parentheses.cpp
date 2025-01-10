/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 * @lcpr version=30204
 *
 * [1021] 删除最外层的括号
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
    string removeOuterParentheses(string s) {
        string ans;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (left++ != 0) {
                    ans += '(';
                }
            } else {
                if (--left != 0) {
                    ans += ')';
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()())(())"\n
// @lcpr case=end

// @lcpr case=start
// "(()())(())(()(()))"\n
// @lcpr case=end

// @lcpr case=start
// "()()"\n
// @lcpr case=end

 */

