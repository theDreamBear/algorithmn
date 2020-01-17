/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (36.78%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 82.7K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j
 * 的差的绝对值最大为 k。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 * 
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        #ifdef DEBUG
        if (nums.size() < 1) {
            return false;
        }
        unordered_map<int, int> hashmap;
        // 找最小值
        for (int i = 0 ; i < nums.size(); ++i) {
            if (hashmap.find(nums[i]) != hashmap.end()) {
                if (i - hashmap[nums[i]] <= k) {
                    return true;
                }
            }
            hashmap[nums[i]] = i;
        }
        return false;
        #endif  //  DEBUG

        if (nums.size() < 1) {
            return false;
        }
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashset.find(nums[i]) != hashset.end()) {
                return true;
            }
            hashset.insert(nums[i]);
            if (hashset.size() > k) {
                hashset.erase(nums[i - k]);
            }
        }
        return false;
    }
};
// @lc code=end

