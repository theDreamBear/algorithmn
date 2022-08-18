/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> se;
        vector<string> ans;
        for (int i = 0; i + 9 < s.size(); i++) {
            string sub = s.substr(i, 10);
            ++se[sub];
            if (se[sub] == 2) {
                ans.push_back(sub);
            }
        }
        return ans;
    }
};
// @lc code=end
