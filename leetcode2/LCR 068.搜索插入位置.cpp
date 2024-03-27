/*
 * @lc app=leetcode.cn id=LCR 068 lang=cpp
 * @lcpr version=30120
 *
 * [LCR 068] 搜索插入位置
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
    int searchInsert1(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end()) {
            return it - nums.begin();
        } else {
            return nums.size();
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (nums[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (nums[low] >= target) {
            return low;
        }
        if (nums[high] >= target) {
            return high;
        }
        return nums.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

