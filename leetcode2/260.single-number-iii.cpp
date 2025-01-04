/*
 * @lc app=leetcode.cn id=260 lang=cpp
 * @lcpr version=30204
 *
 * [260] 只出现一次的数字 III
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
    vector<int> singleNumber(vector<int>& nums) {
        unsigned x = 0;
        for (auto v: nums) {
            x ^= v;
        }
        int lb = x & (-x);
        unsigned int x1 = 0, x2 = 0;
        for (auto v: nums) {
            if (v & lb) {
                x1 ^= v;
            } else {
                x2 ^= v;

            }
        }
        return {int(x1), int(x2)};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

 */

