/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 *
 * https://leetcode-cn.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (51.02%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    101.8K
 * Total Submissions: 198.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 给定一个整数数组，判断是否存在重复元素。
 * 
 * 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,4]
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: [1,1,1,3,3,4,3,2,4,2]
 * 输出: true
 * 
 */
#include <vector>
#include <set>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
 public:

    void insertSortHelper(vector<int >& nums, int low, int high, bool& over) {
        if (over ||low >= high) {
            return;
        }
        for (int i = low + 1; i <= high; ++i) {
            int key = nums[i];
            int j = i - 1;
            for (; j >=0 && nums[j] > key; --j) {
                nums[j+ 1] = nums[j];
            }
            if (j >= 0 && nums[j] == key) {
                over = true;
            }
            nums[j + 1] = key;
        }
        return;
    }
    int partition(vector<int>& nums, int low, int high) {
        int left = low - 1;
        int key = nums[high];
        int i = low;
        for (; i < high; ++i) {
            if (key > nums[i]) {
                ++left;
                if (left != i) {
                    swap(nums[left], nums[i]);
                }
            }
        }
        if (++left != i) {
            swap(nums[left], nums[i]);
        }
        return left;
    }
    void quickSort(vector<int>& nums, int low, int high, bool& over) {
        if (over || low >= high) {
            return;
        }
        int p = partition(nums, low, high);
        if (p - 1 >= low && nums[p - 1] == nums[p]) {
            over = true;
        }
        if (p + 1 <= high && nums[p + 1] == nums[p]) {
            over = true;
        }
        if (p - low <= 5) {
            insertSortHelper(nums, low, p - 1, over);
        } else {
            quickSort(nums, low, p - 1, over);
        }
        if (high - p <= 5) {
            insertSortHelper(nums, p + 1, high, over);
        } else {
            quickSort(nums, p + 1, high, over);
        }
    }

    bool containsDuplicate(vector<int>& nums) {
        #ifdef DEBUG1  //  sudo pip install cpplint 超时 哎
        // 1 排序
        if (nums.size() == 0) {
            return false;
        }
        bool over = false;
        quickSort(nums, 0, nums.size() - 1, over);
        if (over) {
            return true;
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
        #endif  //  DEBUG1
        // 1.1 遍历一次

        //  #ifdef dd
        // 2 hashmap
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashset.find(nums[i]) != hashset.end()) {
                return true;
            }
            hashset.insert(nums[i]);
        }
        return false;
        //  #endif //!dd

        #ifdef DEBUG  // 超时
        // 3 暴力
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
        #endif  // DEBUG
    }
};
// @lc code=end

