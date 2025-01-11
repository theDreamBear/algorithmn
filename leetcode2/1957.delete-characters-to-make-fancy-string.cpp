/*
 * @lc app=leetcode.cn id=1957 lang=cpp
 * @lcpr version=30204
 *
 * [1957] 删除字符使字符串变好
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
    string makeFancyString1(string s) {
        string ans;
        for (auto ch: s) {
            if (ans.size() < 2) ans += ch;
            else {
                int n = ans.size();
                if (ans[n - 1] == ch and ans[n - 2] == ch) continue;
                ans += ch; 
            }
        }
        return ans;
    }

    string makeFancyString(string s) {
        string ans;
        for (auto ch: s) {
            int n = ans.size();
            if (n >= 2 and ans[n - 1] == ch and ans[n - 2] == ch) {
                continue;
            }
            ans += ch;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leeetcode"\n
// @lcpr case=end

// @lcpr case=start
// "aaabaaaa"\n
// @lcpr case=end

// @lcpr case=start
// "aab"\n
// @lcpr case=end

 */

