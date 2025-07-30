/*
 * @lc app=leetcode.cn id=29 lang=cpp
 * @lcpr version=30204
 *
 * [29] 两数相除
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
    int divide1(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            if (divisor == -1) return INT_MAX;
        }
        if (divisor == INT_MIN) return dividend == INT_MIN ? 1: 0;
        if (dividend == 0) return 0;
        bool rev = false;
        if (dividend > 0) {
            dividend = -dividend;
            rev = !rev;
        }
        if (divisor > 0) {
            divisor = -divisor;
            rev = !rev;
        }
        // a, c 都是负数
        auto quick = [&](int a, int x, int c) {
            int ans = 0;
            while (x) {
                if (x & 1) {
                    if (ans < c - a) {
                        return false;
                    }
                    ans += a;
                }
                if (x != 1) {
                    if (a < c - a) {
                        return false;
                    }
                    a += a;
                }
                x >>= 1;
            }
            return true;
        };

        int low = 0, high = INT_MAX, ans = 0;
        while (low + 1 < high) {
            int mid = low + ((high - low) >> 1);
            if (quick(divisor, mid, dividend)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (quick(divisor, high, dividend)) {
            ans = high;
        } else {
            ans = low;
        }
        return rev ? -ans : ans;
    }

    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            if (divisor == -1) return INT_MAX;
        }
        if (divisor == INT_MIN) return dividend == INT_MIN ? 1: 0;
        if (dividend == 0) return 0;
        bool rev = false;
        if (dividend > 0) {
            dividend = -dividend;
            rev = !rev;
        }
        if (divisor > 0) {
            divisor = -divisor;
            rev = !rev;
        }
        vector<int> can{divisor};
        while (can.back() >= dividend - can.back()) can.emplace_back(can.back() << 1);
        int ans = 0;
        for (int i = can.size() - 1; i >= 0; i--) {
            if (can[i] >= dividend) {
                ans += (1 << i);
                dividend -= can[i];
            }
        }
        return rev ? -ans : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n3\n
// @lcpr case=end

// @lcpr case=start
// 7\n-3\n
// @lcpr case=end

 */

