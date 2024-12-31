/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 * @lcpr version=30204
 *
 * [1201] 丑数 III
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
    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1, high = (long long)min({a, b, c}) * n;
        vector<long long> base;
        vector<int> x{a, b, c};
        for (int i = 1; i < (1 << size(x)); i++) {
            int sign = __builtin_popcount(i) % 2 ? 1 : -1;
            // a b c 的lcm 是一个long long
            long long k = 1;
            for (int j = 0; j < size(x); j++) {
                if (i >> j & 1) {
                    k = lcm(k, x[j]);
                } 
            }
            base.push_back(sign * k);
        }
        auto can = [&](long long m) {
            int ans = 0;
            for (auto v: base) {
                if (v > 0) {
                    ans += m / v;
                } else {
                    ans -= (m) / (-v);
                }
            }
            return ans >= n;
        };
        while (low + 1 < high) {
            long long mid = low + (high - low) / 2;
            if (can(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        } 
        if (can(low)) return low;
        return high;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n3\n5\n
// @lcpr case=end

// @lcpr case=start
// 4\n2\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n2\n11\n13\n
// @lcpr case=end

 */

