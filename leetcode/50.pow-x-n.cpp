/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
        尾递归
    */
    double fastPow(double x, long long n, double temp) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return temp * x;
        }
        if (n % 2) {
            return fastPow(x * x, n >> 1, temp * x);
        }
        return fastPow(x * x, n >> 1, temp);
    }

    /*
        循环
    */
    double fastPow2(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        double ans = 1;
        while(n > 0) {
            if (n % 2) {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }

    /*
        观察n的范围, 故需要考虑越界问题
    */
    double myPow(double x, int n) {
        long long N = n;
        if (n < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N, 1.0);
    }
};
// @lc code=end

int main() {
    cout << Solution{}.myPow(2, -2);
}
