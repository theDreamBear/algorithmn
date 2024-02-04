/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30114
 *
 * [17] 电话号码的字母组合
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
    string mp[8] = {
                        "abc",
                        "def",
                        "ghi",
                        "jkl",
                        "mno",
                        "pqrs",
                        "tuv",
                        "wxyz",
                     };

    void backtrack(vector<string>& ans, string& tmp, const string& digits) {
        if (tmp.size() >= digits.size()) {
            ans.push_back(tmp);
            return;
        }
        for (auto c : mp[digits[tmp.size()] - '2']) {
            tmp.push_back(c);
            backtrack(ans, tmp, digits);
            tmp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        string tmp;
        backtrack(ans, tmp, digits);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

