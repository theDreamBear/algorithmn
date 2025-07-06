/*
 * @lc app=leetcode.cn id=2338 lang=cpp
 * @lcpr version=30204
 *
 * [2338] 统计理想数组的数目
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
    // 最暴力记忆话搜索解法
    int idealArrays_tle(int n, int maxValue) {
        // 当前值为i, 下标位置为j的理想数组个数
        vector<vector<int>> f(maxValue + 1, vector<int>(n, -1));
        auto                dfs = [&](auto&& dfs, int i, int j) -> int {
            if (j == n)
                return 1;
            auto& v = f[i][j];
            if (v != -1) {
                return v;
            }
            long long res = 0;
            for (int x = i; x <= maxValue; x += i) {
                res = (res + dfs(dfs, x, j + 1)) % int(1e9 + 7);
            }
            return res;
        };
        return dfs(dfs, 1, 0);
    }

    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        
        // 预处理每个数的质因数分解
        vector<vector<pair<int, int>>> factors(maxValue + 1);
        for (int i = 2; i <= maxValue; ++i) {
            if (factors[i].empty()) { // i是质数
                for (int j = i; j <= maxValue; j += i) {
                    int cnt = 0, tmp = j;
                    while (tmp % i == 0) {
                        tmp /= i;
                        ++cnt;
                    }
                    factors[j].emplace_back(i, cnt);
                }
            }
        }
        
        // 预处理组合数C(n+k-1, k) 用于stars and bars
        vector<vector<int>> comb(n + 20, vector<int>(20, 0));
        comb[0][0] = 1;
        for (int i = 1; i < comb.size(); ++i) {
            comb[i][0] = 1;
            for (int j = 1; j < comb[i].size(); ++j) {
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
            }
        }
        
        long long res = 0;
        for (int i = 1; i <= maxValue; ++i) {
            long long cnt = 1;
            for (auto [p, k] : factors[i]) {
                cnt = (cnt * comb[n + k - 1][k]) % MOD;
            }
            res = (res + cnt) % MOD;
        }
        
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n5\n
// @lcpr case=end

// @lcpr case=start
// 5\n3\n
// @lcpr case=end

 */
