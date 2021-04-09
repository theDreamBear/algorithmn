/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <ranges.h>
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
    /*
        O(n)
        线性查找
    */
    int findPeakElement1(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        long long pre = INT64_MIN;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > pre && nums[i] > nums[i + 1]) {
                return i;
            }
            pre = nums[i];
        }
        return nums.size() - 1;
    }

    /*
        能否二分
    */
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int low = 0, high = nums.size() - 1;
        while (low + 1 < high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (nums[mid] < nums[mid - 1]) {
                high = mid;
            } else {
                low = mid;
            }       
        }
        if (nums[low] < nums[high]) {
            return high;
        }
        return low;
    }
};
// @lc code=end

int main() {
    vector<int> data = {3, 1, 2};
    cout << Solution{}.findPeakElement(data);
}