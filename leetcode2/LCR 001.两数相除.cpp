/*
 * @lc app=leetcode.cn id=LCR 001 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 001] 两数相除
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
    /*
        这个边界问题不好处理
    */
    bool can(int mid, int a, int b) {
        // a < 0
        // b < 0
        // mid > 0
        int res = 0;
        int n = 32 - __builtin_clz(mid);
        int base = b;
        for (int i = 0; i < n; i++) {
            if (mid >> i & 0x1) {
                // 越界的问题 res + (base << i)  < a;
                // 这个边界问题不好处理
                if (a - res > (base << i) || (base << i) >= 0) {
                    return false;
                }
                res += (base << i);
            }
        }
        return res >= a;
    }

    int divide(int a, int b) {
        // 最特殊情况
        if (a == INT_MIN) {
            if (b == -1) {
                return INT_MAX;
            }
            if (b == 1) {
                return INT_MIN;
            }
        }
        if (a == 0) {
            return 0;
        }
        int sign = (a >> 31 == b >> 31) ? 1 : -1;
        if (a > 0) {
            a = -a;
        }
        if (b > 0) {
            b = -b;
        }
        int low = 0, high = INT_MAX;
        while (low + 1 < high) {
            int mid = low + ((high - low) >> 1);
            if (can(mid, a, b)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (can(high, a, b)) {
            if (sign > 0) {
                return high;
            }
            return -high;
        }
        return sign > 0 ?low : -low;
    }

};
// @lc code=end



/*
// @lcpr case=start
// 15\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n-3\n
// @lcpr case=end

// @lcpr case=start
// 0\n1\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

