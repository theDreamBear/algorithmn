/*
 * @lc app=leetcode.cn id=2767 lang=cpp
 * @lcpr version=30204
 *
 * [2767] 将字符串分割为最少的美丽子字符串
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumBeautifulSubstrings1(string s) {
        int n = s.size();
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (f[j] != INT_MAX and s[j] != '0') {
                    int val = 0;
                    for (int k = j; k <= i; k++) {
                        val = (val * 2 + s[k] - '0');
                    }
                    while (val >= 5) {
                        if (val % 5 != 0) {
                            break;
                        }
                        val /= 5;
                    }
                    if (val == 1) {
                        f[i + 1] = min(f[i + 1], f[j] + 1);
                    }
                }
            }
        }
        return f[n] == INT_MAX ? -1: f[n];
    }

    // 可以枚举5的幂
    int minimumBeautifulSubstrings(string s) {
        // 2^15 = 1024 * 32;
        unordered_set<string> pow5;
        for (int i = 0, base = 1; i <= 7; i++, base *= 5) {
            int x = base;
            string bin;
            while (x) {
                bin.push_back((x & 1) + '0');
                x >>= 1;
            }
            ranges::reverse(bin);
            pow5.insert(bin);
        }
        int n = s.size();
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (f[j] != INT_MAX and s[j] != '0') {
                    if (pow5.contains(s.substr(j, i - j + 1))) {
                        f[i + 1] = min(f[i + 1], f[j] + 1);
                    }
                }
            }
        }
        return f[n] == INT_MAX ? -1: f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1011"\n
// @lcpr case=end

// @lcpr case=start
// "111"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n
// @lcpr case=end

 */

