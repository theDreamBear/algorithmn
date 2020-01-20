/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (58.34%)
 * Likes:    474
 * Dislikes: 0
 * Total Accepted:    98.9K
 * Total Submissions: 168.3K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void fakePartition(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int block = low - 1;
        for (int i = 0; i <= high; ++i) {
            if (nums[i] != 0) {
                if (++block != i) {
                    swap(nums[block], nums[i]);
                }
            }
        }
        if (++block < high) {
            swap(nums[block], nums[high]);
        }
    }

    void moveZeroes(vector<int>& nums) {
        fakePartition(nums);
    }
};
// @lc code=end

