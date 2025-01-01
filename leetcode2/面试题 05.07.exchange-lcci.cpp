/*
 * @lc app=leetcode.cn id=面试题 05.07 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 05.07] 配对交换
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
    int exchangeBits(int num) {
        int x = 0x55555555, y = 0xaaaaaaaa;
        return ((num & x) << 1) ^ ((num & y) >> 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

 */

