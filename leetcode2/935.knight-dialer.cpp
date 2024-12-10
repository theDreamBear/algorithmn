/*
 * @lc app=leetcode.cn id=935 lang=cpp
 * @lcpr version=30204
 *
 * [935] 骑士拨号器
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
const int MOD = 1'000'000'007;
long long memo[5001][10];

long long dfs(int i, int j) {
    if (i == 0) return 1;
    if (memo[i][j]) {
        return memo[i][j];
    }
    long long res = 0;
    if (j == 0) {
        res = (dfs(i - 1, 1) + dfs(i - 1, 2)) % MOD;
    } else if (j == 1) {
        res = dfs(i - 1, 0) * 2 % MOD;
    } else if (j == 2) {
        res = (2 * dfs(i - 1, 0) + dfs(i - 1, 3)) % MOD;
    } else if (j == 3) {
        res = 2 * dfs(i - 1, 2) % MOD;
    }
    return memo[i][j] = res;
}
class Solution {
public:
    // 可以直接计算每个节点可以到达的点
    int knightDialer1(int n) {
        vector<vector<int>> dir{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
        vector<string> board{"123", "456", "789", "*0#"};
        int ans = 0;
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, INT_MIN)));
        auto dfs = [&](auto&& dfs, int i, int j, int k) {
            if (k == 1) {
                return 1;
            }
            if (dp[i][j][k] != INT_MIN) return dp[i][j][k];
            int res = 0;
            for (int t = 0; t < 8; t++) {
                int nx = i + dir[t][0];
                int ny = j + dir[t][1];
                if (nx < 0 or nx >= 4 or ny < 0 or ny >= 3 or !isdigit(board[nx][ny])) {
                    continue;
                }
                res = (res +  dfs(dfs, nx, ny, k - 1)) % mod;
            }
            return dp[i][j][k] = res;
        };
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (isdigit(board[i][j])) {
                    ans  = (ans + dfs(dfs, i, j, n)) % mod;
                }
            }
        }
        return ans;
    }

    /**
     * @brief 
     * 
     * dfs(i,0)
dfs(i,1)
dfs(i,2)
dfs(i,3)
=dfs(i−1,1)+dfs(i−1,2)
=2⋅dfs(i−1,0)
=2⋅dfs(i−1,0)+dfs(i−1,3)
=2⋅dfs(i−1,2)
作者：灵茶山艾府
链接：https://leetcode.cn/problems/knight-dialer/solutions/3004116/jiao-ni-yi-bu-bu-si-kao-dpcong-ji-yi-hua-x06l/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     * 
     * @param n 
     * @return int 
     */
    // 同状态合并
    int knightDialer2(int n) {
        if (n == 1) {
            return 10;
        }
        return (dfs(n - 1, 0) * 4 + dfs(n - 1, 1) * 2 + dfs(n - 1, 2) * 2 + dfs(n - 1, 3)) % MOD;
    }

    // 矩阵乘法
    vector<vector<long long>> matrixMul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<long long>> ans(m, vector<long long>(n));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         for (int k = 0; k < n; k++) {
        //             ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
        //         }
        //     }
        // }
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < a[i].size(); k++) {
                if (a[i][k] == 0) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return ans;
    }

    vector<vector<long long>> fastPow(vector<vector<long long>>& a, int n, vector<vector<long long>>& f0) {
        auto res = f0;
        while (n) {
            if (n & 1) res = matrixMul(a, res);
            a = matrixMul(a, a);
            n >>= 1;
        }
        return res;
    }

    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        vector<vector<long long>> a{
            {0, 1, 1, 0},
            {2, 0, 0, 0},
            {2, 0, 0, 1},
            {0, 0, 2, 0}
        };
        vector<vector<long long>> f0{{1}, {1}, {1}, {1}};
        auto m = fastPow(a, n - 1, f0);
        return (m[0][0] * 4 + m[1][0] * 2 +
                m[2][0] * 2 + m[3][0]) % MOD;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3131\n
// @lcpr case=end

 */

