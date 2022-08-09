/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        vector<string> ans;
        string s;
        function<void(int, int)> backtrack = [&](int left, int right) {
            if (left > n) {
                return;
            }
            if (left == n) {
                ans.push_back(std::move(s + string(n - right, ')')));
                return;
            }
            s.push_back('(');
            backtrack(left + 1, right);
            s.pop_back();

            if (left > right) {
                s.push_back(')');
                backtrack(left, right + 1);
                s.pop_back();
            }
        };
        backtrack(0, 0);
        return ans;
    }
};
// @lc code=end

