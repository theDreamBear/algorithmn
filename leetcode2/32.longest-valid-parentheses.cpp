/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
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
    // O(n^3)
    int longestValidParentheses_brute(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int left = 0;
                for (int k = i; k <= j; k++) {
                    if (s[k] == '(') left++;
                    else {
                        if (--left < 0) {
                            break;
                        }
                    }
                }
                if (left == 0) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }

    // O(n^2)
    // 固定左端点
    // 
    int longestValidParentheses(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                int left = 0;
                for (int j = i; j < s.size(); j++) {
                    if (s[j] == '(') left++;
                    else {
                        --left;
                        if (left < 0) {
                            break;
                        }
                        if (left == 0) ans = max(ans, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

