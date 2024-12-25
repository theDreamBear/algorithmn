/*
 * @lc app=leetcode.cn id=3352 lang=cpp
 * @lcpr version=30204
 *
 * [3352] 统计小于 N 的 K 可约简整数
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
#include <string.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start

int f[1000][10];

auto _ = []() {
    //memset(f, 0, sizeof(f));
    for (int j = 0; j < 10; j++) {
        f[1][j] = 1;
    }
    for (int i = 2; i < 1000; i++) {
        for (int j = 1; j < 10; j++) {
            f[i][j] = f[i][j - 1];
            if (!f[i][j]) f[i][j] = f[__builtin_popcount(i)][j - 1];
        }
    }
    return nullptr;
}();


class Solution {
  public:
    int countKReducibleNumbers1(string s, int k) {
        long long dp[801][801];
        memset(dp, -1, sizeof(dp));
        int mod = 1e9 + 7;
        auto dfs = [&](auto&& dfs, int isNum, int isHigh, int cnt, int pos) -> long long {
            if (pos >= s.size()) {
                if (isHigh) {
                    return 0;
                }
                return f[cnt][k - 1];
            }
            if (isNum and !isHigh and dp[cnt][pos] != -1) {
                return dp[cnt][pos];
            }
            int ans = 0;
            if (!isNum) {
                ans = dfs(dfs, 0, 0, 0, pos + 1);
            }
            int low  = 1 - isNum;
            int high = isHigh ? s[pos] - '0' : 1;
            for (auto x = low; x <= high; x++) {
                ans = (ans + dfs(dfs, 1, isHigh and x + '0' == s[pos], cnt + x, pos + 1)) % mod;
            }
            if (isNum and !isHigh) {
                dp[cnt][pos] = ans;
            }
            return ans;
        };
        return dfs(dfs, 0, 1, 0, 0);
    }

    int countKReducibleNumbers(string s, int k) {
        int n = s.size();
        long long dp[801][801];
        memset(dp, -1, sizeof(dp));
        int mod = 1e9 + 7;
        auto dfs = [&](auto&& dfs, int isHigh, int left, int pos) -> long long {
            if (pos >= s.size()) {
                if (isHigh) {
                    return 0;
                }
                return left == 0;
            }
            if (!isHigh and dp[left][pos] != -1) {
                return dp[left][pos];
            }
            int ans = 0;
            int low  = 0;
            int high = isHigh ? s[pos] - '0' : 1;
            for (auto x = low; x <= min(left, high); x++) {
                ans = (ans + dfs(dfs, isHigh and x + '0' == s[pos], left - x, pos + 1)) % mod;
            }
            if (!isHigh) {
                dp[left][pos] = ans;
            }
            return ans;
        };
        long long ans = 0;
        vector<int> f(n);
        for (int i = 1; i < s.size(); i++) {
            f[i] = f[__builtin_popcount(i)] + 1;
            if (f[i] <= k) {
                ans += dfs(dfs, 1, i, 0);
            }
        }
        return ans % mod;
    }

    // 组合数
    int countKReducibleNumbers_good(string s, int K) {
        // 特判无解
        if (s == "1") return 0;
        int n = s.size();

        // 预处理小于等于 n 的数需要几步变成 1
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 2; i <= n; i++) f[i] = f[__builtin_popcount(i)] + 1;

        // 预处理组合数
        const int MOD = 1e9 + 7;
        long long C[n + 1][n + 1];
        memset(C, 0, sizeof(C));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }

        long long ans = 0;
        // 枚举有几个 1
        for (int g = 1; g <= n; g++) if (f[g] <= K - 1) {
            int rem = g;
            // 枚举相同的前缀长度
            for (int i = 0; i < n; i++) if (s[i] == '1') {
                if (rem >= 0) ans = (ans + C[n - 1 - i][rem]) % MOD;
                rem--;
            }
        }
        return ans;
    }
};

// @lc code=end

/*
// @lcpr case=start
// "111"\n1\n
// @lcpr case=end

// @lcpr case=start
// "1000"\n2\n
// @lcpr case=end

// @lcpr case=start
// "1"\n3\n
// @lcpr case=end

 */
