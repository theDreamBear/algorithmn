/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII1(vector<int>& nums) {
        partition(nums.begin(), nums.end(), [](int val) {
            return val % 2 == 0;
        });
        for (int i = 1, j = nums.size() - 2; i < j; i += 2, j -= 2) {
            swap(nums[i], nums[j]);
        }
        return nums;
    }
    /*
        [0, pos] ok 区域
        [pos + 1, i)
        [i, sz]
    */
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int j = 1;
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] % 2 != 0) {
                while (j < nums.size() && nums[j] % 2 != 0) {
                    j += 2;
                }
                swap(nums[i], nums[j]);
                
            }
        }
        return nums;
    }
};
// @lc code=end

