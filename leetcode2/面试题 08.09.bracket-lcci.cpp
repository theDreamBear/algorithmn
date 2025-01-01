/*
 * @lc app=leetcode.cn id=面试题 08.09 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.09] 括号
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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        auto dfs = [&](auto&& dfs, int i, int val) {
            if (i == 2 * n) {
                if (val == 0)
                ans.push_back(cur);
                return;
            }
            if (val + i + 2 <= 2 * n) {
                cur.push_back('(');
                dfs(dfs, i + 1, val + 1);
                cur.pop_back();
            }
            if (val > 0) {
                cur.push_back(')');
                dfs(dfs, i + 1, val - 1);
                cur.pop_back();
            }
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};
// @lc code=end



