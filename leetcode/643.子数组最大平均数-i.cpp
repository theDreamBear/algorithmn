/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
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
        前缀和
    */
    double findMaxAverage(vector<int>& nums, int k) {
        // 多一个元素, 简化逻辑
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = (sums[i] + nums[i]);
        }
        double max_avg = -1000000;
        for (int i = k; i <= nums.size(); ++i) {
            double sum = sums[i] - sums[i - k];
            if (sum / k > max_avg) {
                max_avg = sum / k;
            }
        }
        return max_avg;
    }
};
// @lc code=end

