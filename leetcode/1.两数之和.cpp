/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.16%)
 * Likes:    7224
 * Dislikes: 0
 * Total Accepted:    738.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
#include <unordered_map>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hashmap;
        for (size_t i = 0; i < nums.size(); i++)
        {
            hashmap[nums[i]] = i;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            auto pos = hashmap.find(target - nums[i]);
            if (pos != hashmap.end() && (*pos).second > i) {
                return {int(i), (*pos).second};
            }
        }
        return vector<int>{};
    }
};
// @lc code=end

