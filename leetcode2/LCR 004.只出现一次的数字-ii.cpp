/*
 * @lc app=leetcode.cn id=LCR 004 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 004] 只出现一次的数字 II
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
    int singleNumber(vector<int>& nums) {
        int v1 = 0, v2 = 0;
        for (auto v : nums) {
            v2 = ~v1 & (v2 ^ v);
            v1 = ~v2 & (v1 ^ v);
        }
        return v2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,1,0,1,100]\n
// @lcpr case=end

 */

