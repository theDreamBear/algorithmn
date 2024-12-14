/*
 * @lc app=leetcode.cn id=2571 lang=cpp
 * @lcpr version=30204
 *
 * [2571] 将整数减少到零需要的最少操作数
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
    int minOperations1(int n) {
        int ans = 0;
        while (n) {
            if (n % 2 == 0) {
                n >>= 1;
            } else {
                if ((n & 3) == 3) {
                    n += 1;
                } else {
                    n -= 1;
                }
                ans++;
                n >>= 1;
            }
        }
        return ans;
    }
    // 对于连续1  被>2个0隔绝
    // n =    001111
    // 3n =   101101 
    // ^  =   100010 刚好需要两步 
    int minOperations(int n) {
        return __builtin_popcount(n ^ (3 * n));
    }
};
// @lc code=end



/*
// @lcpr case=start
// 39\n
// @lcpr case=end

// @lcpr case=start
// 54\n
// @lcpr case=end

 */

