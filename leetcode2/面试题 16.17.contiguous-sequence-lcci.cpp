/*
 * @lc app=leetcode.cn id=面试题 16.17 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.17] 连续数列
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if (sum < 0) {
            //     sum = nums[i];
            // } else {
            //     sum += nums[i];
            // }
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

 */

