/*
 * @lc app=leetcode.cn id=2909 lang=cpp
 * @lcpr version=30204
 *
 * [2909] 元素和最小的山形三元组 II
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
    int minimumSum(vector<int>& nums) {
        // 后缀mm
        int n = nums.size();
        vector<int> suf(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; i--) suf[i] = min(suf[i + 1], nums[i]);
        int preMin = nums[0];
        int ans = INT_MAX;
        for (int i = 1; i + 1 < n; i++) {
            if (nums[i] > preMin and nums[i] > suf[i + 1]) {
                ans = min(ans, preMin + suf[i + 1] + nums[i]);
            }
            preMin = min(preMin, nums[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [8,6,1,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,7,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,3,4,5]\n
// @lcpr case=end

 */

