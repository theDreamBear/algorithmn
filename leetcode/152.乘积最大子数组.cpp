/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    int maxProduct(vector<int>& nums) {
        vector<int> max_nums(nums.size() + 1);
        vector<int> min_nums(nums.size() + 1);
        max_nums[0] = 1;
        min_nums[0] = 1;
        int max_val = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int mm = min_nums[i] * nums[i];
            int ma = max_nums[i] * nums[i];
            if (nums[i] > 0) {
                max_nums[i + 1] = max(nums[i], ma);
                min_nums[i + 1] = min(nums[i], mm);
            } else {
                max_nums[i + 1] = max(nums[i], mm);
                min_nums[i + 1] = min(nums[i], ma);
            }
            if (max_nums[i + 1] > max_val) {
                max_val = max_nums[i + 1];
            }
        }
        return max_val;
    }
};
// @lc code=end
