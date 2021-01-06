/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
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
    int findMaxConsecutiveOnes_1(vector<int>& nums) {
        int ans = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            // 过滤0
            while (right < nums.size() && nums[right] == 0) {
                ++right;
            }
            left = right;
            // 计算1
            while (right < nums.size() && nums[right] == 1) {
                ++right;
            }
            int len = right - left;
            if (len > ans) {
                ans = len;
            }
            left = right;
        }
        return ans;
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ++count;
            } else {
                ans = max(ans, count);
                count = 0;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};
// @lc code=end

