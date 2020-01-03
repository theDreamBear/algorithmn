/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (52.04%)
 * Likes:    34
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 24.3K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给定一个整数数组 nums，将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：[5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * -50000 <= A[i] <= 50000
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 插入排序超时
    void insertSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int key = nums[i];
            int j = i - 1;
            for (; j >=0 && nums[j] > key; --j) {
                nums[j+ 1] = nums[j];
            }
            nums[j + 1] = key;
        }
        return;
    }

    void insertSortHelper(vector<int>& nums, int low, int high) {
        if (low > high) {
            return;
        }
        for (int i = low + 1; i <= high; ++i) {
            int key = nums[i];
            int j = i - 1;
            for (; j >=0 && nums[j] > key; --j) {
                nums[j+ 1] = nums[j];
            }
            nums[j + 1] = key;
        }
        return;
    }
    // 快排排序
    int partition(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return low;
        }
        int blockIndex = low - 1, i = low;
        int randIndex = rand() % (high - low + 1) + low;
        swap(nums[randIndex], nums[high]);
        int key = nums[high];
        for(; i < high; ++i) {
            if (nums[i] <= key) {
                ++blockIndex;
                if (blockIndex != i) {
                    swap(nums[blockIndex], nums[i]);
                }
            }
        }
        if (++blockIndex != i) {
            swap(nums[blockIndex], nums[i]);
        }
        return blockIndex;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int q = partition(nums, low, high);
        int left = q - 1, right = q + 1;
        while(left >= low && nums[q] == nums[left]) {
            --left;
        }
        if (left - low + 1 <= 5) {
            insertSortHelper(nums, low, left);
        } else {
            quickSort(nums, low, q - 1);
        }
        while(high >= right && nums[q] == nums[right]) {
            ++right;
        }
        if (high - right + 1 <= 5 ) {
            insertSortHelper(nums, right, high);
        } else {
            quickSort(nums, q + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0 , nums.size() - 1);
        return nums;
    }
};
// @lc code=end

