/*
 * @lc app=leetcode.cn id=2598 lang=cpp
 * @lcpr version=30204
 *
 * [2598] 执行操作后的最大 MEX
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
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> va(value);
        for (auto v: nums) {
            va[(v % value + value) % value]++;
        }
        int res = 0;
        while (va[res % value]--) {
            res++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-10,7,13,6,8]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,-10,7,13,6,8]\n7\n
// @lcpr case=end

 */

