/*
 * @lc app=leetcode.cn id=371 lang=cpp
 * @lcpr version=30204
 *
 * [371] 两整数之和
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
    int getSum(int a, int b) {
        while (b) {
            int c = (a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n
// @lcpr case=end

 */

