#include <vector>
using namespace std;

/*
1. i, v
2. dp[i] 能否装到 i
3 递归方程  dp[i] = dp[i] | dp[i - A[j]]

*/
int backPack(int m, vector<int> &A) {
    // write your code here
    bool dp[m + 1];
    fill(dp, dp + m + 1, false);
    dp[0] = true;
    int max = 0;
    for (int i = 0; i < A.size(); ++i) {
        max += A[i];
        // 0 1 背包 每个只能用一次
        max = min(m, max);
        for (int j = max; j >= 1; --j) {
            if (!dp[j] && j - A[i] >= 0) {
                dp[j] = dp[j - A[i]];
            }
        }
    }
    for (int i = m; i >= 0; --i) {
        if (dp[i] == true) {
            return i;
        }
    }
    return 0;
}

// i 当前选取序号
/* 每一步有两种选择取或者不取
 *
 *
 * */
int backPackHelper_bad(int i, int sum, int m,  vector<int> &A) {
    if (i >= A.size()) {
        return sum;
    }
    int res = backPackHelper_bad(i + 1, sum, m, A);

    if (sum + A[i] <= m) {
        res = max(res, backPackHelper_bad(i + 1, sum + A[i], m, A));
    }
    return res;
}

int backPack_bad(int m, vector<int> &A) {
    // write your code here
    return backPackHelper_bad(0, 0, m, A);
}

bool backPackHelper_good(int i, int m, vector<int> &A, vector<int>& dp) {
    if (dp[m]) {
        return dp[m];
    }
    if (i >= A.size()) {
        return false;
    }
    bool left = backPackHelper_good(i + 1, m, A, dp);
    if (A[i] <= m) {
        left |= backPackHelper_good(i + 1, m - A[i], A, dp);
    }
    return dp[m] = left;
}

// 能否m
int backPack_good(int m, vector<int> &A) {
    // write your code here
    vector<int> dp(m + 1, false);
    dp[0] = true;
    backPackHelper_good(0, m, A, dp);
    return dp[m];
}

// i 当前选取序号
int backPackHelper(int i, int sum, int m, vector<int> &A) {
    if (i >= A.size()) {
        return sum;
    }
    int res = backPackHelper(i + 1, sum, m, A);

    if (sum + A[i] <= sum) {
        res = max(res, backPackHelper(i + 1, sum + A[i], m, A));
    }
    return res;
}

int backPack_R(int m, vector<int> &A) {
    // write your code here
    return backPackHelper(0, 0, m, A);
}

/*
1. dp[i][w] 最大 value

*/

int backPackII(int m, vector<int> &A, vector<int> &V) {
    // write your code here
    vector<vector<int>> dp(A.size() + 1, vector<int>(m + 1, 0));
    int res = 0;
    for (int i = 1; i <= A.size(); ++i) {
        for (int j = m; j >= 0; --j) {
            if (i - 1 >= 0) {
                dp[i][j] = dp[i - 1][j];
                if (j - A[i - 1] >= 0) {
                    dp[i][j] =
                        max(dp[i][j], dp[i - 1][j - A[i - 1]] + V[i - 1]);
                }
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}

int backPackIV(vector<int> &nums, int target) {
    // write your code here
    return 0;
}