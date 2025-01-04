/*
 * @lc app=leetcode.cn id=1680 lang=cpp
 * @lcpr version=30204
 *
 * [1680] 连接连续二进制数字
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
    int concatenatedBinary1(int n) {
        unsigned long long ans = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            int x = 32 - __builtin_clz(i);
            ans = ((ans << x) | i) % mod;
        }
        return ans;
    }

    const int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long ans = 0;
        int shift = 0;
        for (int i=1; i<=n; i++) {
            if ((i & (i-1)) == 0) {
                shift++;
            }
            ans = ((ans << shift) + i) % M;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 12\n
// @lcpr case=end

 */

