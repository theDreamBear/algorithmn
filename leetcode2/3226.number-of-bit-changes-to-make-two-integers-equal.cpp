/*
 * @lc app=leetcode.cn id=3226 lang=cpp
 * @lcpr version=30204
 *
 * [3226] 使两个整数相等的位更改次数
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
    int minChanges(int n, int k) {
        if ((n & k) != k) {
            return -1;
        }
        return __builtin_popcount(n ^ k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 13\n4\n
// @lcpr case=end

// @lcpr case=start
// 21\n21\n
// @lcpr case=end

// @lcpr case=start
// 14\n13\n
// @lcpr case=end

 */

