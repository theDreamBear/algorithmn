/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
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
    /*
        dp[i] 以 nums[i] 结尾的最大长度
        dp[i + 1] = dp[k] + 1;

        憨批看清楚题目
    */
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int i = 1;
        int count = 1;
        int max_count = 1;
        while (i < nums.size()) {
            if (nums[i] > nums[i - 1]) {
                ++count;
            } else {
                if (max_count < count) {
                    max_count = count;
                }
                count = 1;
            }
            ++i;
        }
        if (max_count < count) {
                max_count = count;
        }
        return max_count;
    }
};
// @lc code=end

