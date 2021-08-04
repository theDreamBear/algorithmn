/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
    /*
       [j+1,n−1] 的下标范围内使用二分查找
       最大满足 nums[i]+nums[j]>nums[k]
       的k

       */
    int binary_find(const vector<int> &nums, const int j, const int target) {
        int low = j + 1, high = (int) nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target > nums[mid]) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return low - 1;

    }

    int _binary_find(const vector<int> &nums, const int j, const int target, int &low) {
        if (j + 1 > low) {
            low = j + 1;
        }
        int high = (int) nums.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (target > nums[mid]) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (nums[high] < target) {
            low = high;
            return high;
        }
        if (nums[low] < target) {
            return low;
        }
        low = j;
        return j;
    }

public:
    int triangleNumber1(vector<int> &nums) {
        int ans = 0;
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int k = i;
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int res = _binary_find(nums, j, nums[i] + nums[j], k);
                ans += (res - j);

            }
        }
        return ans;
    }

    int triangleNumber(vector<int> &nums) {
        int ans = 0;
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int k = i;
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int sum = nums[i] + nums[j];
                while (k + 1 < nums.size() && nums[k + 1] < sum) {
                    ++k;
                }
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};

// @lc code=end

