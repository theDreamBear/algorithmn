/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
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
    /*
        暴力解法O(n);
    */
    int search1(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    /*
        二分
        写代码前一定要分清楚各种情况
    */
    int search2(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] == target) {
                return low;
            }   
            if (nums[high] == target) {
                return high;
            }

            // 1. low - high 升序
            if (nums[low] < target && nums[high] > target) {
                if (target > nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
                continue;
            }
            // 2. low - high  降序
            if (nums[low] > target && nums[high] < target) {
                if (target > nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                continue;
            }
            // 3. 左mid
            if (nums[mid] > nums[low]) {
                if (target > nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                continue;
            }
            // 4. 右mid
            if (target > nums[mid] && target < nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    /*
        旋转后两个部分必有一个是有序的
    */
    int search(vector<int>& nums, int target) {

    }
};
// @lc code=end

int main() {
    vector<int> data = {5, 1, 2, 3, 4};
    cout << Solution{}.search(data, 1);
}
