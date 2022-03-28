/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
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
bool isArithmeticArray(const vector<int>& nums) {
    if (nums.size() <= 1) {
        return true;
    }
    int diff = nums[1] - nums[0];
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] - nums[i - 1] != diff) {
            return false;
        }
    }
    return true;
}

class Solution {
 public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for (int i = 0; i < l.size(); i++) {
            int li = l[i];
            int ri = r[i];
            vector<int> temp(nums.begin() + li, nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            ans[i] = isArithmeticArray(temp);
        }
        return ans;
    }
};
// @lc code=end

