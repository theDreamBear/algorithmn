/*
 * @lc app=leetcode.cn id=面试题 08.11 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.11] 硬币
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
int dp[4][1000010];
class Solution {
public:
    // bad, 计算有问题
    // 1 5 1
    // 1 1 5
    // 5 1 1
    // 其实是一样的, 这个会导致这个不一样
    int waysToChange_bad(int n) {
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int x: {1, 5, 10, 25}) {
                if (i >= x) dp[i] = (dp[i] + dp[i - x]) % (int)(1e9 + 7);
            }
        }
        return dp[n];
    }

    int waysToChange_tle2(int n) {
        int mod = 1e9 + 7;
        vector<int> val{1, 5, 10, 25};
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&& dfs, int i, int left)->int {
            if (i >= val.size() or left == 0) {
                return left == 0;
            }
            if (val[i] > left) return 0;
            auto& ans = dp[i][left];
            if (ans != -1) return ans;
            ans = 0;
            for (int x = 0; x <= left / val[i]; x++) {
                ans = (ans + dfs(dfs, i + 1, left - x * val[i])) % mod;
            }
            return ans;
        };
        return dfs(dfs, 0, n);
    }

    // 超时
    int waysToChange_tle(int n) {
        int mod = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= (n - i) / 5; j++) {
                for (int k = 0; k <= (n - i - j * 5) / 10; k++) {
                    if ((n - i - j * 5 - 10 * k) % 25 == 0) ans = (ans + 1) % mod;
                }
            }
        }
        return ans;
    }

    int waysToChange1(int n) {
        int mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int x: {1, 5, 10, 25}) {
            for (int i = x; i <= n; i++) {
                dp[i] = (dp[i] + dp[i - x]) % (int)(1e9 + 7);
            }
        }
        return dp[n];

    }

    // 勉强过了
    int waysToChange2(int n) {
        int mod = 1e9 + 7;
        vector<int> val{1, 5, 10, 25};
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&& dfs, int i, int left)->int {
            if (i >= val.size() or left == 0) {
                return left == 0;
            }
            if (val[i] > left) return 0;
            auto& ans = dp[i][left];
            if (ans != -1) return ans;
            ans = dfs(dfs, i + 1, left);
            ans = (ans + dfs(dfs, i, left - val[i])) % mod;
            return ans;
        };
        return dfs(dfs, 0, n);
    }

    int waysToChange(int n) {
        int mod = 1e9 + 7;
        vector<int> val{1, 5, 10, 25};
        long long ans = 0;
        // 枚举25
        for (int i = 0; i <= n / 25; i++) {
            int res = n - 25 * i;
            // 10 5 确定, 1 就确定了
            long long a0 = res / 10;
            long long b0 = res % 10 / 5;
            ans = (ans + (a0 + b0 + 1) * (a0 + 1)) % mod;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

