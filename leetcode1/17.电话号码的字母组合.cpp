/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        string strs[] {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
        vector<string> ans;
        string s;
        function<void(int)> backtrack = [&](int pos) {
            if (pos >= digits.size()) {
                ans.push_back(s);
                return;
            }
            string word = strs[digits[pos] - '0'];
            for (int i = 0; i < word.size(); i++) {
                s.push_back(word[i]);
                backtrack(pos + 1);
                s.pop_back();
            }
        };
        backtrack(0);
        return ans;
    }
};
// @lc code=end

