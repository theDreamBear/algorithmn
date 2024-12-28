/*
 * @lc app=leetcode.cn id=2318 lang=cpp
 * @lcpr version=30204
 *
 * [2318] 不同骰子序列的数目
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
//        pp p last
const int MX = 10001;
const int MOD = 1e9 + 7;
int dp[10001][7][7];
int  f[MX + 1][7][7];

auto _ = []() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            f[2][i][j] = j != i and gcd(i + 1, j + 1) == 1;
        }
    }
    for (int i = 2; i < MX; i++) {
        for (int p = 0; p < 6; p++) {
            for (int last = 0; last < 6; last++) {
                for (int c = 0; c < 6; c++) {
                    if (c == p or c == last or gcd(last + 1, c + 1) != 1) {
                        continue;
                    }
                    f[i + 1][last][c] = (f[i + 1][last][c] + f[i][p][last]) % MOD;
                }
            }
        }
    }
    return 0;
}();

class Solution {
  public:
    int distinctSequences1(int n) {
        // 1 任何
        // 偶数 奇数
        // 3  1 2 3 4 5
        // 00

        // 0 1 2 3 4 5 6
        // 1 2 3 4 5 6
        // 5 1 2 3 4 6

        // 3 1 2 4 5

        // 2 1 3 5
        // 4 1 3 5
        // 6 1 5
        memset(dp, -1, sizeof dp);
        int  mod = 1e9 + 7;
        auto dfs = [&](auto&& dfs, int i, int p, int last) {
            if (i >= n) {
                return 1;
            }
            auto& ans = dp[i][p][last];
            if (ans != -1)
                return ans;
            ans = 0;
            for (int c = 1; c <= 6; c++) {
                // 2 4 6
                if (last != 0 and last % 2 == 0) {
                    // 奇数且不同
                    if (p == c or last == c or c % 2 == 0 or (last == 6 and c == 3)) {
                        continue;
                    }
                    ans = (ans + dfs(dfs, i + 1, last, c)) % mod;
                    // if (p == c or last == c or gcd(c, last) != 1) {
                    //     continue;
                    // }
                    // ans = (ans + dfs(dfs, i + 1, last, c)) % mod;
                } else {
                    if (c == p or c == last or (last == 3 and c == 6) or (last == 6 and c == 3)) {
                        continue;
                    }
                    ans = (ans + dfs(dfs, i + 1, last, c)) % mod;
                }
            }
            return ans;
        };
        return dfs(dfs, 0, 0, 0);
    }

    int distinctSequences2(int n) {
        memset(dp, -1, sizeof dp);
        int  mod = 1e9 + 7;
        auto dfs = [&](auto&& dfs, int i, int p, int last) {
            if (i <= 0) {
                return 1;
            }
            auto& ans = dp[i][p][last];
            if (ans != -1)
                return ans;
            ans = 0;
            for (int c = 1; c <= 6; c++) {
                if (p == c or last == c or (last != 0 and gcd(c, last) != 1)) {
                    continue;
                }
                ans = (ans + dfs(dfs, i - 1, last, c)) % mod;
            }
            return ans;
        };
        return dfs(dfs, n, 0, 0);
    }

    // 改成递推
    int distinctSequences3(int n) {
        if (n == 1) return 6;
        int ans = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                ans = (ans + f[n][i][j]) % MOD;
            }
        }
        return ans;
    }

    int distinctSequences(int n) {
        if (n == 1) return 6;
        int t[MX + 1][6];
        for (int i = 0; i < 6; i++) {
            t[1][i] = 1;
        }
        for (int i = 2; i <= MX; i++) {
            for (int j = 0; j < 6; j++) {
                long long s = 0;
                for (int k = 0; k < 6; k++) {
                    if (k != j and gcd(k + 1, j + 1) == 1) {
                        s += t[i - 1][k] - t[i - 2][j];
                    }
                }
                if (i > 3) s += t[i - 2][j];
                t[i][j] = s % MOD;
            }
        }
        long ans = 0;
        for (int v: t[n]) {
            ans += v;
        }
        return (ans % MOD + MOD) % MOD;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
