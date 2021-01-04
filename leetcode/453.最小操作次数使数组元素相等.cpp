/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
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
    int minMoves(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int k = 0;
        long long sum = 0;
        int mm = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (nums[i] < mm) {
                mm = nums[i];
            }
        }
        return sum - mm * nums.size();
    }
};
// @lc code=end

