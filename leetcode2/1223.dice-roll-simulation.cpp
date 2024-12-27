/*
 * @lc app=leetcode.cn id=1223 lang=cpp
 * @lcpr version=30204
 *
 * [1223] 掷骰子模拟
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
class Solution {
public:
    int dieSimulator1(int n, vector<int>& rollMax) {
        //rollMax.push_back(0);
        const int mod = 1e9 + 7;
        int dp[n + 1][8][16];
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&& dfs, int i, int j, int cnt) {
            if (i >= n) {
                return 1;
            }
            auto& ans = dp[i][j][cnt];
            if (ans != -1) return ans;
            ans = 0;
            for (int k = 1; k <= 6; k++) {
                if (k == j) {
                    // 妹的
                    if (cnt + 1 <= rollMax[j - 1]) {
                        ans = (ans + dfs(dfs, i + 1, j, cnt + 1)) % mod;
                    }
                } else {
                    ans = (ans + dfs(dfs, i + 1, k, 1)) % mod;
                }
            }
            return ans;
        };
        return dfs(dfs, 0, 7, 0);
    }

    int dieSimulator2(int n, vector<int>& rollMax) {
        //rollMax.push_back(0);
        const int mod = 1e9 + 7;
        int dp[2][8][17];
        memset(dp, 0, sizeof dp);
        // 初始化
        int ft = 0, st = 1;
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= rollMax[j - 1]; k++) {
                dp[ft][j][k] = 1;
            }
        }
        // 递推
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= 6; j++) {
                //memset(dp[st], 0, sizeof dp[1]);
                for (int k = 1; k <= rollMax[j - 1]; k++) {
                    dp[st][j][k] = 0;
                    for (int x = 1; x <= 6; x++) {
                        dp[st][j][k] = (dp[st][j][k] + (x == j ? dp[ft][x][k + 1]: dp[ft][x][1])) % mod;
                    }
                }
            }
            swap(ft, st);
        }
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            ans = (ans + dp[ft][i][1]) % mod;
        }
        return ans;
    }

    // 发现枚举x那一步可以优化
    int dieSimulator3(int n, vector<int>& rollMax) {
        //rollMax.push_back(0);
        const int mod = 1e9 + 7;
        long long dp[2][8][17];
        memset(dp, 0, sizeof dp);
        // 初始化
        int ft = 0, st = 1;
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= rollMax[j - 1]; k++) {
                dp[ft][j][k] = 1;
            }
            
        }
        // 计算sum
        int p = 0;
        for (int i = 1; i <= 6; i++) {
            p = (p + dp[ft][i][1]) % mod;
        }
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= 6; j++) {
                for (int k = 1; k <= rollMax[j - 1]; k++) {
                    dp[st][j][k] = (p - dp[ft][j][1] + dp[ft][j][k + 1] + mod) % mod;
                }
            }
            swap(ft, st);
            p = 0;
            for (int i = 1; i <= 6; i++) {
                p = (p + dp[ft][i][1]) % mod;
            }
        }
        return p;
    }


    // 究极公式
    int dieSimulator(int n, vector<int>& rollMax) {
        //rollMax.push_back(0);
        const int mod = 1e9 + 7;
        int m = rollMax.size();
        int f[n][m], s[n];
        for (int j = 0; j < m; j++) f[0][j] = 1;
        s[0] = m;
        for (int i = 1; i < n; i++) {
            s[i] = 0;
            for (int j = 0; j < m; j++) {
                int res = s[i - 1], mx = rollMax[j];
                if (i > mx) res -= s[i - mx - 1] - f[i - mx - 1][j];
                else if (i == mx) --res;
                f[i][j] = (res % mod + mod) % mod;
                s[i] = (s[i] + f[i][j]) % mod;
            }
        }
        return s[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[1,1,2,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,1,1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[1,1,1,2,2,3]\n
// @lcpr case=end

 */

