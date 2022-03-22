/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
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
 public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        partial_sum(nums.begin(), nums.end(), ans.begin());
        return ans;
    }
};
// @lc code=end
