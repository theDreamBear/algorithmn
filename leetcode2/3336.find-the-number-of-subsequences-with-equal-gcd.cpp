/*
 * @lc app=leetcode.cn id=3336 lang=cpp
 * @lcpr version=30204
 *
 * [3336] 最大公约数相等的子序列数量
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
int dp[210][210][210];
const int mod = 1e9 + 7;
class Solution {
public:
    // 1199ms
    int subsequencePairCount1(vector<int>& nums) {
        // i, g1, g2
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&& dfs, int i, int g1, int g2)->int {
            if (i >= nums.size()) {
                return g1 != 0 and g1 == g2;
            }
            auto& ans = dp[i][g1][g2];
            if (ans != -1) {
                return ans;
            }
            // 都不选
            ans = dfs(dfs, i + 1, g1, g2);
            // 序列一
            ans = (ans + dfs(dfs, i + 1, gcd(g1, nums[i]), g2)) % mod;
            // 序列二
            ans = (ans + dfs(dfs, i + 1, g1, gcd(g2, nums[i]))) % mod;
            return ans;
        };
        return dfs(dfs, 0, 0, 0);
    }

    // 1224ms
    int subsequencePairCount2(vector<int>& nums) {
        // i, g1, g2
        long long f[2][210][210]{};
        int ft = 0, st = 1, n = nums.size();
        int m = ranges::max(nums);
        for (int g1 = 1; g1 <= m; g1++) {
            f[ft][g1][g1] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int g1 = m; g1 >= 0; g1--) {
                for (int g2 = m; g2 >= 0; g2--) {
                    f[st][g1][g2] = (f[ft][g1][g2] + f[ft][gcd(nums[i], g1)][g2] + f[ft][g1][gcd(nums[i], g2)]) % mod;
                }
            }
            swap(ft, st);
        }
        return f[ft][0][0];
    }

    int subsequencePairCount2(vector<int>& nums) {
        // i, g1, g2
        long long f[210][210]{};
        int n = nums.size();
        int m = ranges::max(nums);
        for (int g1 = 1; g1 <= m; g1++) {
            f[g1][g1] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            // f[0][0] 会依赖f[0][x] 这个有依赖更新前的值的问题
            f[0][0] = (f[0][0] + f[gcd(nums[i], 0)][0] + f[0][gcd(nums[i], 0)]) % mod;
            for (int g2 = m; g2 > 0; g2--) {
                int g1 = 0;
                f[g1][g2] = (f[g1][g2] + f[gcd(nums[i], g1)][g2] + f[g1][gcd(nums[i], g2)]) % mod;
            }
            for (int g1 = m; g1 > 0; g1--) {
                int g2 = 0;
                f[g1][g2] = f[g2][g1];
            }
            for (int g1 = m; g1 >= 1; g1--) {
                for (int g2 = m; g2 >= 1; g2--) {
                    f[g1][g2] = (f[g1][g2] + f[gcd(nums[i], g1)][g2] + f[g1][gcd(nums[i], g2)]) % mod;
                }
            }
        }
        return f[0][0];
    }

    int subsequencePairCount(vector<int>& nums) {
        // i, g1, g2
        long long f[210][210]{};
        int n = nums.size();
        int m = ranges::max(nums);
        for (int g1 = 1; g1 <= m; g1++) {
            f[g1][g1] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            // f[0][0] 会依赖f[0][x] 这个有依赖更新前的值的问题
            f[0][0] = (f[0][0] + f[gcd(nums[i], 0)][0] + f[0][gcd(nums[i], 0)]) % mod;
            for (int g2 = m; g2 > 0; g2--) {
                int g1 = 0;
                f[g1][g2] = (f[g1][g2] + f[gcd(nums[i], g1)][g2] + f[g1][gcd(nums[i], g2)]) % mod;
            }
            for (int g1 = m; g1 > 0; g1--) {
                int g2 = 0;
                f[g1][g2] = f[g2][g1];
            }
            for (int g1 = m; g1 >= 1; g1--) {
                for (int g2 = m; g2 >= 1; g2--) {
                    f[g1][g2] = (f[g1][g2] + f[gcd(nums[i], g1)][g2] + f[g1][gcd(nums[i], g2)]) % mod;
                }
            }
        }
        return f[0][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [10,20,30]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */

