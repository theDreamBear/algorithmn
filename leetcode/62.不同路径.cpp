/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int A[100][100];

    int uniquePaths1(int m, int n) {
        A[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            A[i][0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            A[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                A[i][j] = A[i -1][j] + A[i][j - 1];
            }
        }
        return A[m - 1][n -1];
    }

    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        double res = 1;
        for (int i = 1; i <= n -1; ++i) {
            res = res * (N - n + 1 + i) / i;
        }
        return res;
    }
};
// @lc code=end

