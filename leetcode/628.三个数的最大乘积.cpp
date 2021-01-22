/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
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
    // 最大三个数的成绩
    //  1. 最大的三个数的积
    //  2. 最大正数和最小的两个负数的乘积
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_val = INT_MIN;
        int last = nums.size() - 1;

        int right = nums[last] * nums[last - 1] * nums[last - 2] ;
        int left = nums[last] * nums[1] * nums[0];
        if (left > right) {
            return left;
        }
        return right;
    }
};
// @lc code=end

