/*
 * @lc app=leetcode.cn id=LCR 134 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 134] Pow(x, n)
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
    // double myPow(double x, int n) {
    //     if (n == INT_MIN) {
    //         double value = 1.0 / myPow(x * x, -1 * (n >> 1));
    //         return value * value;
    //     }
    //     if (n < 0) {
    //         return 1.0 / myPow(x, -n);
    //     }
    //     if (n == 0) {
    //         return 1;
    //     }
    //     if (n == 1) {
    //         return x;
    //     }
    //     if (n & 0x1) {
    //         return x * myPow(x * x, n >> 1);
    //     }
    //     return myPow(x * x, n >> 1);
    // }

    double myPowLL(double x, long long n) {
        if (n < 0) {
            return 1.0 / myPowLL(x, -n);
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        double ans = 1;
        while (n > 1) {
            if (n & 0x1) {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans * x;
    }

    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        return myPowLL(x, n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2.00000\n10\n
// @lcpr case=end

// @lcpr case=start
// 2.10000\n3\n
// @lcpr case=end

// @lcpr case=start
// 2.00000\n-2\n
// @lcpr case=end

 */

