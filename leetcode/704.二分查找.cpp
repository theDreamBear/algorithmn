/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
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
    int search1(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        // 这个地方能不能等于? 可以
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low + 1 <  high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid;
            } else if (nums[mid] > target) {
                high = mid;
            } else {
                return mid;
            }
        }
        if (nums[high] < target) {
            return -1;
        }
        if (nums[high] == target) {
            return high;
        }
        if (nums[low] != target) {
            return -1;
        }
        return low;
    }
};
// @lc code=end

