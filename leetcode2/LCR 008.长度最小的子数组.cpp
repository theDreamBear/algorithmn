/*
 * @lc app=leetcode.cn id=LCR 008 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 008] 长度最小的子数组
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total < target) {
            return 0;
        }
        if (total == target) {
            return ans;
        }
        // [left, right) 当前区间， sum = 0;
        int left = 0, right = 0;
        long long sum = 0;
        while (right < nums.size()) {
            sum += nums[right++];
            while (left < right and sum >= target) {
                ans = min(ans, right - left);
                sum -= nums[left];
                ++left;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

