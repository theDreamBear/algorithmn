/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
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
    bool searchHelper(vector<int>& nums, int low, int high, int target) {
        if (low > high) {
            return false;
        }
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[high]) {
                if (nums[mid] <= target && nums[high] >= target) {
                    low = mid;
                } else {
                    high = mid;
                }
            } else if (nums[mid] > nums[high]) {
                if (nums[low] <= target && nums[mid] >= target) {
                    high = mid;
                } else {
                    low = mid;
                }
            } else {
                // 相等时判断不了，需要两边都处理
                if (nums[mid] == target) {
                    return true;
                }
                if (searchHelper(nums, low, mid - 1, target)) {
                    return true;
                }
                return searchHelper(nums, mid, high, target);
            }
        }
        if (nums[low] == target) {
            return true;
        }
        return nums[high] == target;
    }

    bool search(vector<int>& nums, int target) {
        return searchHelper(nums, 0, nums.size() - 1, target);
    }
};
// @lc code=end

int main() {
    vector<int> data = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    cout << Solution{}.search(data, 2);
}
