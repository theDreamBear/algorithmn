/*
 * @lc app=leetcode.cn id=2400 lang=cpp
 * @lcpr version=30204
 *
 * [2400] 恰好移动 k 步到达某一位置的方法数目
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
    int numberOfWays1(int startPos, int endPos, int k) {
        int offset = 1000;
        vector<vector<int>> memo(3001, vector<int>(1001, INT_MIN));
        int mod = 1e9 + 7;
        auto dfs = [&](auto&& dfs, int p, int left)->int {
            if (abs(endPos - p) > left or left < 0) {

                return 0;
            }
            if (abs(endPos - p) == left) {
                return 1;
            }
            if (memo[p + offset][left] != INT_MIN) {
                return memo[p + offset][left];
            }
            long long res = 0;
            res = (res + dfs(dfs, p - 1, left - 1)) % mod;
            res = (res + dfs(dfs, p + 1, left - 1)) % mod;
            return memo[p + offset][left] = res % mod;
        };
        return dfs(dfs, startPos, k);
    }
    // 递推
    int numberOfWays2(int startPos, int endPos, int k) {
        if (k < abs(endPos - startPos)) return 0;
        int offset = 1000;
        vector<vector<int>> f(4001, vector<int>(1001, 0));
        int mod = 1e9 + 7;
        // 最左位置  startPos - k;
        // 最右位置  startPos + k;
        // diff = abs(endPos - startPos);

        // 初始化 f[end + offset][abs(endPos - startPos)] = 1;
        f[endPos + offset][0] = 1;
        int left = endPos, right = endPos;
        for (int i = 1; i <= k; i++) {
            left--;
            right++;
            for (int j = left; j <= right; j++) {
                f[j + offset][i] = (f[j - 1 + offset][i - 1] + f[j + 1 + offset][i - 1]) % mod;
            }
        }
        return f[startPos + offset][k];
    }

    // 数学递推
    int numberOfWays3(int startPos, int endPos, int k) {
        if (startPos < endPos) {
            swap(startPos, endPos);
        }
        if (k < abs(endPos - startPos) or (endPos - startPos + k) % 2 != 0) return 0;
        // 数字
        int diff = endPos - startPos;
        // 2a - k = diff
        // a = (diff + k) / 2;
        // 求
        // c(k, a)
        int mod = 1e9 + 7;
        vector<vector<long long>> f(k + 1, vector<long long>(k + 1));
        // c(n, m) = c(n - 1, m) + c(n - 1, m - 1);
        for (int i = 0; i <= k; i++) {
            f[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
            }
        }
        return f[k][(diff + k) / 2];
    }

    // 数学逆元
    int numberOfWays(int startPos, int endPos, int k) {
        if (startPos < endPos) {
            swap(startPos, endPos);
        }
        if (k < abs(endPos - startPos) or (endPos - startPos + k) % 2 != 0) return 0;
        // 数字
        int diff = endPos - startPos;
        // 2a - k = diff
        // a = (diff + k) / 2;
        // 求
        // c(k, a)
        int mod = 1e9 + 7;
        vector<long long> inv(k + 1);
        inv[1] = 1;
        for (int i = 2; i <= k; i++) {
            inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        }
        long long ans = 1;
        for (int i = 1; i <= (diff + k) / 2; i++) {
            ans = ans * (k - i + 1) % mod * inv[i] % mod;
        }
        return ans;
    }
    // 
};
// @lc code=end



/*
// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n5\n10\n
// @lcpr case=end

 */

