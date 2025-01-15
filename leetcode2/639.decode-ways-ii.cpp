/*
 * @lc app=leetcode.cn id=639 lang=cpp
 * @lcpr version=30204
 *
 * [639] 解码方法 II
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
    int numDecodings1(string s) {
        int n = s.size();
        vector<long long> f(n + 1);
        f[0] = 1;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            // 取1位
            if (s[i] >= '1' and s[i] <= '9') f[i + 1] = (f[i + 1] +  f[i]) % mod;
            else if (s[i] == '*') f[i + 1] = (f[i + 1] + 9 * f[i]) % mod;
            // 取2位
            if (i > 0 and s[i - 1] != '0') {
                int s1, e1;
                if (s[i - 1] == '*') {
                    s1 = 1, e1 = 2;
                } else {
                    s1 = e1 = s[i - 1] - '0';
                }
                int s2, e2;
                if (s[i] == '*') {
                    s2 = 1;
                    e2 = 9;
                } else {
                    s2 = e2 = s[i] - '0';
                }
                for (int x = s1; x <= e1; x++) {
                    for (int y = s2; y <= e2; y++) {
                        int val = x * 10 + y;
                        if (val >= 10 and val <= 26) {
                            f[i + 1] = (f[i + 1] +  f[i - 1]) % mod;
                        }
                    }
                }
            }
        }
        return f[n];
    }

    int numDecodings(string s) {
        int n = s.size();
        long long prepre = 0, pre = 1;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long f = 0;
            // 取1位
            if (s[i] >= '1' and s[i] <= '9') f = (f + pre) % mod;
            else if (s[i] == '*') f = (f + 9 * pre) % mod;
            // 取2位
            if (i > 0 and s[i - 1] != '0') {
                int s1, e1;
                if (s[i - 1] == '*') {
                    s1 = 1, e1 = 2;
                } else {
                    s1 = e1 = s[i - 1] - '0';
                }
                int s2, e2;
                if (s[i] == '*') {
                    s2 = 1;
                    e2 = 9;
                } else {
                    s2 = e2 = s[i] - '0';
                }
                for (int x = s1; x <= e1; x++) {
                    for (int y = s2; y <= e2; y++) {
                        int val = x * 10 + y;
                        if (val >= 10 and val <= 26) {
                            f = (f +  prepre) % mod;
                        }
                    }
                }
            }
            prepre = pre;
            pre = f;
        }
        return pre;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "*"\n
// @lcpr case=end

// @lcpr case=start
// "1*"\n
// @lcpr case=end

// @lcpr case=start
// "2*"\n
// @lcpr case=end

 */

