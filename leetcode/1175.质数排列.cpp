/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
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
    int primeScreen(int n) {
        vector<bool> screen(n + 1, true);
        int ct = 0;
        for (int i = 2; i < n + 1; ++i) {
            if (screen[i]) {
                ++ct;
                int step = i;
                for (int k = i + step; k < n + 1; k += step) {
                    screen[k] = false;
                }
            }
        }
        return ct;
    }

    int fullPermutation(int n, int m, int mod) {
        // int 会越界
        long long ans = 1;
        while (m >= 2 && n >= 2) {
            ans *= (m * n);
            --m;
            --n;
            if (ans >= mod) {
                ans %= mod;
            }

        }
        while (m >= 2) {
            ans *= m;
            --m;
            if (ans >= mod) {
                ans %= mod;
            }
        }
        while (n >= 2) {
            ans *= n;
            --n;
            if (ans >= mod) {
                ans %= mod;
            }
        }
        return ans;
    }

    int numPrimeArrangements(int n) {
        int prime_count = primeScreen(n);
        int other = n - prime_count;
        int mod = 1e9 + 7;
        return fullPermutation(prime_count, other, mod);
    }
};
// @lc code=end

