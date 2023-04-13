/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution1 {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        // 预处理
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        //  dp[k][i][j] 前k个 zero 个数 == i, one 个数 == j 的最大长度
        // 初始化 都为0
        // A[i].first = zt, A[i].second = ot;
        // dp[k][i][j] = max(dp[k - 1][i][j], dp[k- 1][i - zt][j-ot] + 1
        int ans = 0;
        for (int k = 0; k < strs.size(); k++) {
            int oc = 0;
            int zc = 0;
            for (auto c: strs[k]) {
                if (c == '0') {
                    zc++;
                } else if (c == '1') {
                    oc++;
                }
            }
            for (int i = 0; i < m + 1; i++) {
                for (int j = 0; j < n + 1; j++) {
                    dp[k + 1][i][j] = dp[k][i][j];
                    if (i >= zc && j >= oc) {
                        dp[k + 1][i][j] = max(dp[k + 1][i][j], dp[k][i - zc][j - oc] + 1);
                    }
                    ans = max(ans, dp[k + 1][i][j]);
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        // 预处理
       vector<vector<int>> dp(m + 1, vector<int>(n + 1));
       dp[0][0] = 0;
        //  dp[k][i][j] 前k个 zero 个数 == i, one 个数 == j 的最大长度
        // 初始化 都为0
        // A[i].first = zt, A[i].second = ot;
        // dp[k][i][j] = max(dp[k - 1][i][j], dp[k- 1][i - zt][j-ot] + 1
        int ans = 0;
        for (int k = 0; k < strs.size(); k++) {
            int oc = 0;
            int zc = 0;
            for (auto c: strs[k]) {
                if (c == '0') {
                    zc++;
                } else if (c == '1') {
                    oc++;
                }
            }
            for (int i = m; i >= zc; i--) {
                for (int j = n; j >= oc; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zc][j - oc] + 1);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        // 预处理
        vector<int> dp((m + 1) * (n + 1), -1);
        dp[0] = 0;
        //  dp[k][i][j] 前k个 zero 个数 == i, one 个数 == j 的最大长度
        // 初始化 都为0
        // A[i].first = zt, A[i].second = ot;
        // dp[k][i][j] = max(dp[k - 1][i][j], dp[k- 1][i - zt][j-ot] + 1
        int ans = 0;
        for (int k = 0; k < strs.size(); k++) {
            int oc = 0;
            int zc = 0;
            for (auto c: strs[k]) {
                if (c == '0') {
                    zc++;
                } else if (c == '1') {
                    oc++;
                }
            }
            for (int i = m; i >= zc; i--) {
                for (int j = n; j >= oc; j--) {
                    int idx_cur = i * (n + 1) + j;
                    int idx = (i - zc) * (n + 1) + j - oc;
                    if (dp[idx] != -1) {
                        dp[idx_cur] = max(dp[idx_cur], dp[idx] + 1);
                    }
                    ans = max(ans, dp[idx_cur]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

