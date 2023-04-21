/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
bool isContiguous(char left, char right) {
    return (left + 1) % 26 == right % 26;
}

class Solution1 {
public:
    int findSubstringInWraproundString(string s) {
        unordered_set<string> sset;
        int left = 0, right = 0;
        // [left, right)
        while (left < s.size()) {
            while (right < s.size()) {
                if (right + 1 == s.size()) {
                    right++;
                    break;
                }
                char cl = s[right];
                char cr = s[++right];
                if (!isContiguous(cl, cr)) {
                    break;
                }
            }
            string sub = s.substr(left, right - left);
            sset.insert(sub);
            left = right;
        }
        unordered_set<string> ans;
        for (auto str: sset) {
           int n = str.size();
           for (int i = 0; i < n; i++) {
               for (int j = 0; j <= i; j++) {
                   string temp = str.substr(j, i - j + 1);
                   ans.insert(temp);
               }
           }
        }
        return ans.size();
    }
};

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26);
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i && isContiguous(s[i - 1], s[i])) {
                k++;
            } else {
                k = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end

