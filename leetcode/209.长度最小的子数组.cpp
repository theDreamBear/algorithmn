/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
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
    /* 滑动窗口问题
        [left, right)

    */
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, len = INT_MAX;
        for (; right < nums.size();) {
            if (sum < s) {
                sum += nums[right];
                ++right;
                while (left < right && sum >= s) {
                    if (len > right - left) {
                        len = right - left;
                    }
                    sum -= nums[left];
                    ++left;
                }
            }
        }
        if (len == INT_MAX) {
            return 0;
        }
        return len;
    }
};
// @lc code=end
