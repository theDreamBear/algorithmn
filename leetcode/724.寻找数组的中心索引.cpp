/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>
#include <numeric>

using namespace std;
// @lc code=start
class Solution {
public:
    int pivotIndex1(vector<int>& nums) {
        int left = 0, right = 0;
        for (auto val : nums) {
            right += val;
        }
        for (int i = 0; i < nums.size(); ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            } else {
                left += nums[i];
            }
        }
        return -1;
    }

    int pivotIndex(vector<int>& nums) {
        int sum = 0, total = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

