/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
    int partition(int low, int high, vector<int>& nums, int k) {
        if (low >= high) {
            return low;
        }
        int barrier = low - 1;
        int temp = nums[high];
        for (int i = low; i < high; ++i) {
            if (nums[i] >= temp) {
                ++barrier;
                if (barrier != i) {
                    swap(nums[barrier], nums[i]);
                }
            }
        }
        if (++barrier != high) {
            swap(nums[barrier], nums[high]);
        }
        return barrier;
    }

    // 快速选择算法
    int findKthLargestHelper(int low, int high, vector<int>& nums, int k) {
        if (nums.size() < k) {
            return -1;
        }
        int p = partition(low, high, nums, k);
        if (p + 1 == k) {
            return nums[p];
        }
        if (p + 1 < k) {
            return findKthLargestHelper(p + 1, high, nums, k);
        }
        return findKthLargestHelper(low, p - 1, nums, k);
    }

    int findKthLargest_1(vector<int>& nums, int k) {
        return findKthLargestHelper(0, nums.size() - 1, nums, k);
    }

    int findKthLargest(vector<int>& nums, int k) { return -1; }
};
// @lc code=end
