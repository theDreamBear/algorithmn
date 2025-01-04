/*
 * @lc app=leetcode.cn id=2419 lang=cpp
 * @lcpr version=30204
 *
 * [2419] 按位与最大的最长子数组
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
    int longestSubarray(vector<int>& nums) {
        int ma = ranges::max(nums);
        int ans = 1;
        for (int i = 0; i < nums.size();) {
            int start = i++;
            while (i < nums.size() and nums[i] == nums[start]) i++;
            if (nums[start] == ma) {
                ans = max(ans, i - start);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

