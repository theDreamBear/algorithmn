/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        // 
        auto left = [&](int k) {
            int low = 0, high = n - 1;
            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                if (nums[mid] >= k) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            if (nums[low] >= k) {
                return low;
            }
            if (nums[high] >= k) {
                return high;
            }
            // 没有匹配到
            return high + 1;
        };
        // auto right = [&]() {
        //     int low = 0, high = n - 1;
        //     while (low + 1 < high) {
        //         int mid = (low + high) >> 1;
        //         if (nums[mid] <= target) {
        //             low = mid;
        //         } else {
        //             high = mid;
        //         }
        //     }
        //     if (nums[low] != target and nums[high] != target) {
        //         return -1;
        //     }
        //     if (nums[high] == target) {
        //         return high;
        //     }
        //     return low;
        // };
        auto l = left(target);
        if (l == n or nums[l] != target) {
            return {-1, -1};
        }
        auto r = left(target + 1);
        return {l, r - 1};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

