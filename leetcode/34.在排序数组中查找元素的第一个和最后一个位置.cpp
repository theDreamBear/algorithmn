/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        auto high = upper_bound(nums.begin(), nums.end(), target);
        if (low != nums.end() && *low == target) {
            return {int(low - nums.begin()), int(high - nums.begin()) - 1};
        }
        return {-1, -1};
    }
};
// @lc code=end
