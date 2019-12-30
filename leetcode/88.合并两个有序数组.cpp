/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (45.97%)
 * Likes:    372
 * Dislikes: 0
 * Total Accepted:    94.3K
 * Total Submissions: 205K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(nums1.begin(), nums1.begin() + m);
        //
        int lIndex = 0, rIndex = 0, index = 0;
        while(lIndex < m && rIndex < n) {
            if (tmp[lIndex] <= nums2[rIndex]) {
                nums1[index++] = tmp[lIndex++];
            } else {
                nums1[index++] = nums2[rIndex++];
            }
        }
        while(lIndex < m) {
            nums1[index++] = tmp[lIndex++];
        }
        while(rIndex < n) {
            nums1[index++] = nums2[rIndex++];
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lIndex = m - 1, rIndex = n - 1, index = m + n - 1;
        while(lIndex >= 0 && rIndex >= 0) {
            if (nums1[lIndex] > nums2[rIndex]) {
                nums1[index--] = nums1[lIndex--];
            } else {
                nums1[index--] = nums2[rIndex--];
            }
        }
        while(lIndex >= 0) {
            nums1[index--] = nums1[lIndex--];
        }
        while(rIndex >= 0) {
            nums1[index--] = nums2[rIndex--];
        }
    }
};
// @lc code=end

