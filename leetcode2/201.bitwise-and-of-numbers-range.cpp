/*
 * @lc app=leetcode.cn id=201 lang=cpp
 * @lcpr version=30204
 *
 * [201] 数字范围按位与
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
    int rangeBitwiseAnd1(int left, int right) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int lb = (left >> i) & 1, rb = (right >> i) & 1;
            if (lb == rb and lb == 1 and (right - left + 1 <= (1 << i))) {
                ans |= (1 << i);
            }
        }
        return ans;
    }

    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        int m = (32 - __builtin_clz(left ^ right));
        return left & ~((1u << m) - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n7\n
// @lcpr case=end

// @lcpr case=start
// 0\n0\n
// @lcpr case=end

// @lcpr case=start
// 1\n2147483647\n
// @lcpr case=end

 */

