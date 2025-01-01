/*
 * @lc app=leetcode.cn id=面试题 05.06 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 05.06] 整数转换
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
    int convertInteger(int A, int B) {
        return __builtin_popcount(A ^ B);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 29 （或者0b11101）\n15（或者0b01111）\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

