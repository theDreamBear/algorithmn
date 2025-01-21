/*
 * @lc app=leetcode.cn id=7 lang=cpp
 * @lcpr version=30204
 *
 * [7] 整数反转
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // [-2147483648, 2147483647]
    int reverse1(int x) {
        if (x == 0) return x;
        int sign = x >= 0 ? 1 : -1;
        string s = to_string(x);
        int e = 0;
        if (sign == -1) e = 1;
        int rev = 0, base = 10;
        for (int f = s.size() - 1; f >= e; f--) {
            int v = s[f] - '0';
            // 正整数
            if (sign == 1 and (rev ==  214748364 and v > 7 or rev >  214748364)) {
                return 0;
            } else if (sign == -1 and (rev ==  -214748364 and v > 8 or rev < -214748364)) {
                return 0;
            }
            rev = rev * base + sign * (s[f] - '0');
        }
        return rev;
    }

    int reverse(int x) {
        if (x == 0) return x;
        int ans = 0;
        for (; x;  x /= 10) {
            if (ans < INT_MIN / 10 or ans > INT_MAX / 10) {
                return 0;
            }
            int q = x % 10;
            ans = ans * 10 + q;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 123\n
// @lcpr case=end

// @lcpr case=start
// -123\n
// @lcpr case=end

// @lcpr case=start
// 120\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */

