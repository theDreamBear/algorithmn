/*
 * @lc app=leetcode.cn id=LCR 126 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 126] 斐波那契数
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
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int mod = 1e9 + 7;
        long long mod2 = (long long)1e15;
        long long pp = 0, p = 1;
        int t = 1;
        while (t++ < n) {
            long long tmp = p;
            p += pp;
            pp = tmp;

            p %= mod;
            pp %= mod;
        }
        return p % mod;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

