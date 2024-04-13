// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=918 lang=cpp
 * @lcpr version=30122
 *
 * [918] 环形子数组的最大和
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
    pair<int, int> cal(vector<int>& nums, int start, int end, int step) {
        if (start == end) {
            return {0, 0};
        }
        int ans = nums[start];
        int sum = nums[start];
        int ei = start;
        for (int i = start + step;  i != end; i += step) {
            sum += nums[i];
            if (sum > ans) {
                ans = sum;
                ei = i;
            }
        }
        return {ans, ei};
    }

    int maxSubarraySumCircular_bad(vector<int>& nums) {
        int n = nums.size();
        auto left = cal(nums, 0, n, 1);
        int lv = left.first;
        auto lr = cal(nums, n - 1, left.second, -1);
        if (lr.first > 0) {
            lv += lr.first;
        }

        auto right = cal(nums, n - 1, -1, -1);
        int rv = right.first;
        auto rl = cal(nums, 0, right.second, 1);
        if (rl.first > 0) {
            rv += rl.first;
        }
        int mid = nums[0], sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            mid = max(mid, sum);
        }
        return max({lv, rv, mid});
    }

    int maxSubarraySumCircular1(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        int ma = nums[0], mas = nums[0];
        int mn = nums[0], mns = nums[0];
        for (int i = 1; i < n; i++) {
            if (mas <= 0) {
                mas = nums[i];
            } else {
                mas += nums[i];
            }
            ma = max(ma, mas);
            if (mns >= 0) {
                mns = nums[i];
            } else {
                mns += nums[i];
            }
            mn = min(mn, mns);
        }
        if (mn == total) {
            return ma;
        }
        return max(ma, total - mn);
    }

    // 动态规划 + 枚举
    int maxSubarraySumCircular2(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], sum = nums[0];
        vector<int> leftMax(n);
        leftMax[0] = nums[0];
        int left_sum = nums[0];
        for (int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
            left_sum += nums[i];
            leftMax[i] = max(leftMax[i - 1], left_sum);
        }
        int rightSum = 0;
        for (int i = n - 1; i > 0; i--) {
            rightSum += nums[i];
            ans = max(ans, rightSum + leftMax[i - 1]);
        }
        return ans;
    }

    // 单调队列 + 前缀和
    // 为什么前缀和可以, 因为至少需要取一个数
    // 单调递增队列 且队列长度最大为n

};
// @lc code=end



/*
// @lcpr case=start
// [1,-2,3,-2]\n
// @lcpr case=end

// @lcpr case=start
// [5,-3,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,-2,2,-3]\n
// @lcpr case=end

 */

