/*
 * @lc app=leetcode.cn id=3007 lang=cpp
 * @lcpr version=30204
 *
 * [3007] 价值和小于等于 K 的最大数字
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
class Solution {
  public:
    long long findMaximumNumber1(long long k, int x) {
        // 计算从low, high 刚好等会k 的max
        long long low = 0, high = 1e15;

        auto can = [&](long long value) {
            string s;
            while (value) {
                s.push_back((value & 1) + '0');
                value >>= 1;
            }
            // ranges::reverse(s);
            long long dp[2][2][64][64];
            memset(dp, -1, sizeof(long long) * 2 * 2 * 64 * 64);
            auto dfs = [&](auto&& dfs, int isLow, int isHigh, int cnt, int pos) -> long long {
                if (pos < 0) {
                    return cnt;
                }
                long long& ans = dp[isLow][isHigh][cnt][pos];
                if (ans != -1) {
                    return ans;
                }
                // 0
                ans = dfs(dfs, isLow, isHigh and '0' == s[pos], cnt, pos - 1);
                // 1
                if (isHigh and s[pos] == '0') {
                    return ans;
                }
                ans += dfs(dfs, 0, isHigh and '1' == s[pos], cnt + ((pos + 1) % x == 0), pos - 1);
                return ans;
            };
            auto res = dfs(dfs, 1, 1, 0, s.size() - 1);
            return res <= k;
        };
        while (low + 1 < high) {
            auto mid = low + (high - low) / 2;
            if (can(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (can(high)) {
            return high;
        }
        return low;
    }

    long long findMaximumNumber2(long long k, int x) {
        // 计算从low, high 刚好等会k 的max
        long long low = 0, high = 1e15;
        auto can = [&](long long value) {
            long long res = 0;
            for (long long i = 0; value >= (1ll << i); i++) {
                if ((i + 1) % x != 0) {
                    continue;
                }
                long long x   = (1ll << (i + 1));
                long long sub = (value + 1) / x * x;
                res += sub / 2;
                if (value + 1 > sub + x / 2) {
                    res += (value + 1 - sub - x / 2);
                }
            }
            return res <= k;
        };
        while (low + 1 < high) {
            auto mid = low + (high - low) / 2;
            if (can(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (can(high)) {
            return high;
        }
        return low;
    }

    long long findMaximumNumber3(long long k, int x) {
        // 计算从low, high 刚好等会k 的max
        long long low = 0, high = 1e15;
        auto can = [&](long long value) {
            long long res = 0;
            for (long long i = 0; value >= (1ll << i); i++) {
                if ((i + 1) % x != 0) {
                    continue;
                }
                long long x = (1ll << (i + 1));
                long long sub = (value) / x * x;
                res += sub / 2;
                if (value >> i & 1) {
                    res += (value + 1 - sub - x / 2);
                }
            }
            return res <= k;
        };
        while (low + 1 < high) {
            auto mid = low + (high - low) / 2;
            if (can(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (can(high)) {
            return high;
        }
        return low;
    }

    // 试填法
    long long findMaximumNumber(long long k, int x) {
        long long num = 0, pre = 0;
        for (long long i = __lg(k + 1 << x); i >= 0; i--) {
            long long add = (pre << i) + (i / x << i >> 1);
            if (add <= k) {
                k -= add;
                num |= 1ll << i;
                pre += (i + 1) % x == 0;
            }
        }
        return num - 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 9\n1\n
// @lcpr case=end

// @lcpr case=start
// 7\n2\n
// @lcpr case=end

 */
