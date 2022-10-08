/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    bool isPara(const char* s, int low , int high) {
        while(low < high) {
            if (s[low] != s[high]) {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }

    // 动态规划
    // 状态 前i个字符的最小切分次数
    // 转移方程  dp[i] = min(dp[j - 1] + 1) 且 s[j - 1, i - 1]为回文串
    // dp[0] = 0
    // 答案 dp[n]
    int minCut2(string s) {
        if (s.size() == 1) {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n + 1);
        // 前0个字符
        dp[0] = 0;
        // 前i 个字符的情况
        for (int i = 1; i < n + 1; i++) {
            dp[i] = dp[i - 1] + 1;
            // 整体是个回文串
            if (isPara(s.c_str(), 0, i - 1)) {
                dp[i] = 0;
                continue;
            }
            for (int j = 2; j < i; j++) {
                if (isPara(s.c_str(), j - 1, i - 1)) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp.back();
    }

    void preProcess(const string& s, vector<vector<bool>> & pp) {
        for (int i = 0; i < s.size(); i++) {
            pp[i][i] = true;
            for (int l = i - 1, r = i + 1; l >= 0 && r < s.size(); l--, r++) {
                if (s[l] == s[r]) {
                    pp[l][r] = pp[l + 1][r - 1];
                }
            }
            int j = i + 1;
            if (j >= s.size()) {
                continue;
            }
            if (s[i] == s[j]) {
                pp[i][j] = true;
            }
            for (int l = i - 1, r = j + 1; l >= 0 && r < s.size(); l--, r++) {
                if (s[l] == s[r]) {
                    pp[l][r] = pp[l + 1][r - 1];
                }
            }
        }
    }

    // s[j - 1, i - 1]为回文串 是否为回文串这个可以预处理求的
    int minCut(string s) {
        if (s.size() == 1) {
            return 0;
        }
        int n = s.size();
        vector<vector<bool>> pp(n, vector<bool>(n));
        preProcess(s, pp);

        vector<int> dp(n + 1);
        // 前0个字符
        dp[0] = 0;
        // 前i 个字符的情况
        for (int i = 1; i < n + 1; i++) {
            dp[i] = dp[i - 1] + 1;
            // 整体是个回文串
            if (pp[0][i - 1]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 2; j < i; j++) {
                if (pp[j - 1][i - 1]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end

