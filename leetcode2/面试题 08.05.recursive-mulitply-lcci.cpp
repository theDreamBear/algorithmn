/*
 * @lc app=leetcode.cn id=面试题 08.05 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.05] 递归乘法
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
    // int mul(int x, int y) {
    //     while (y) {
    //         int z = (x & y) << 1;
    //         x = x ^ y;
    //         y = z;
    //     }
    //     return x;
    // }

    int multiply(int A, int B) {
        int ans = 0;
        while (B) {
            if (B & 1)  ans += A;
            A <<= 1;
            B >>= 1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n10\n
// @lcpr case=end

// @lcpr case=start
// 3\n4\n
// @lcpr case=end

 */

