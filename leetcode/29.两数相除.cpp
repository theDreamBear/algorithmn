/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    long long abs(int val) {
        long long y = val >> 31;
        return y ^ (y + val);
    }

    int divide(int dividend, int divisor) {
        long long sign = 1;
        if ((dividend >> 31) != (divisor >> 31)) {
            sign = -1;
        }
        long long divd = abs(dividend);
        long long divr = abs(divisor);
        if (divr > divd) {
            return 0;
        }
        long long i = 0;
        long long n = divd;
        int exp = 1;
        while (((long long)divr << exp) <= n) {
            ++exp;
        }
        --exp;
        while (n >= divr) {
            i += (1ll << exp);
            n -= (divr << exp);
            while (n >= divr && ((long long)divr << exp) > n) {
                --exp;
            }
        }
        if (sign == -1) {
            i = ~(i - 1);
        }
        if (i > INT_MAX) {
            return INT_MAX;
        }
        return i;
    }
};
// @lc code=end

int main() {
    int d = -2147483648, r = -1;
    cout << Solution{}.divide(d, r);
}
