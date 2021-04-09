/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
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

using namespace std;
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int min_val = 5001;
        while (low + 1 < high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] > nums[low]) {
                if (nums[low] < min_val) {
                    min_val = nums[low];
                }
                low = mid;
            } else {
                if (nums[mid] < min_val) {
                    min_val = nums[mid];
                }
                high = mid;
            }
        }
        if (nums[low] < min_val) {
            min_val = nums[low];
        }
        if (nums[high] < min_val) {
            min_val = nums[high];
        }
        return min_val;
    }
};
// @lc code=end

