/*
 * @lc app=leetcode.cn id=896 lang=cpp
 * @lcpr version=30204
 *
 * [896] 单调数列
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
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 2) return true;

        auto cmp = [&](auto op) {
            for (int i = 1; i < nums.size(); i++) {
                if (!op(i, i - 1)) {
                    return false;
                }
            }
            return true;
        };
        return cmp([&](int i, int j) {
            return nums[i] <= nums[j];
        }) or cmp([&](int i, int j) {
            return nums[i] >= nums[j];
        });
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2]\n
// @lcpr case=end

 */

