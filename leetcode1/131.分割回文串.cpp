/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(const string& str) {
        for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return {};
        }
        vector<vector<string>> ans;
        vector<string> cur;
        function<void(int)> backtrack = [&](int pos) {
            if (pos >= s.size()) {
                ans.push_back(cur);
            }
            for (int i = pos; i < s.size(); i++) {
                string sub = s.substr(pos, i - pos + 1);
                if (isPalindrome(sub)) {
                    cur.push_back(sub);
                    backtrack(i + 1);
                    cur.pop_back();
                }
            }
        };
        backtrack(0);
        return ans;
    }
};
// @lc code=end

