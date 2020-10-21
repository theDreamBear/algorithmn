/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
    int uniquePaths1(int m, int n) {
        int A[100][100];
        A[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            A[i][0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            A[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                A[i][j] = A[i - 1][j] + A[i][j - 1];
            }
        }
        return A[m - 1][n - 1];
    }

    long long factorial(int m, int start) {
        if (m == 0) {
            return 1;
        }
        long long res = 1;
        for (int i = start; i <= m; ++i) {
            res *= i;
        }
        return res;
    }

    int uniquePaths(int m, int n) {
        int N = m + n - 2;
#define DEBUG
#ifdef DEBUG
        // wrong
        long long l, r;
        // 会越界
        l = factorial(N, n);
        r = factorial(m - 1, 1);
        cout << l << " " << r << endl;
        return l / r;
#endif  // DEBUG

#ifdef MATHMATICS
        double res = 1;
        for (int i = 1; i <= n - 1; ++i) {
            res = res * (N - n + 1 + i) / i;
        }
        return res;
#endif  // MATHMATICS
    }

    int uniquePaths_compressArray(int m, int n) {
        int ah[n];
        fill(ah, ah + n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                ah[j] += ah[j - 1];
            }
        }
        return ah[n - 1];
    }
};
// @lc code=end

int main() {
   return 0;
}