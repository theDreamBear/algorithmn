/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> table;
        for (int i = 0; i < nums.size(); i++) {
            table[nums[i]] = i;
        }    
        for (int i = 0; i < nums.size(); i++) {
            int another = target - nums[i];
            if (table.count(another) && table[another] != i) {
                return {i, table[another]};
            }
        }
        return {};
    }

    // 两层循环也可以
    // 排序后两根指针  ?? sb le 不能排序
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     sort(nums.begin(), nums.end());
    //     int left = 0, right = 0;
    //     while (right < nums.size()) {
    //         while (nums[left] + nums[right] < target) {
    //             right++;
    //         }
    //         if (nums[left] + nums[right] == target) {
    //             if (left == right) {
    //                 ++right;
    //             } else {
    //                 return {left, right};
    //             }
    //         }
    //         while (left < right && nums[left] + nums[right] > target) {
    //             left++;
    //         }
    //     }
    //     return {};
    // }
};
// @lc code=end

