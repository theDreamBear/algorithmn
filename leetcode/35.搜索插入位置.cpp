/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (44.70%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    101.1K
 * Total Submissions: 226.2K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 二分查找
    int searchInsert(vector<int>& nums, int target) {
        #ifdef STL
        auto pos = lower_bound(nums.begin(), nums.end(), target);
        return pos - nums.begin();
        #endif // STL
        
        /** 1. 目标是第一个元素之前
         *  2. 目标是最好一个元素之后
         *  3. 目标在中间 找到第一个 >= target 的值
         * 
         * 
         * **/
        if (nums[0] >= target) {
            return 0;
        }
        if (nums[nums.size() - 1] < target) {
            return nums.size();
        }
        // 通用二分查找
        int low = 0, high = nums.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (nums[low] >= target) {
            return low;
        }
        if (nums[high] <= target) {
            return high;
        }
        return high + 1;
    }
};
// @lc code=end
