/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
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
        O(n) 时间复杂度， O(1)空间复杂度， 不用除法
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int r = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= r;
            r *= nums[i];
        }
        return ans;
    }
};
// @lc code=end

