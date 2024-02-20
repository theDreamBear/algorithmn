/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30116
 *
 * [53] 最大子数组和
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
    int maxSubArray1(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        int ans = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmp < 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            ans = max(ans, tmp);
        }
        return ans;
    }

     int maxSubArray(vector<int>& nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }
        int mid = low + ((high - low) >> 1);
        int left = maxSubArray(nums, low, mid);
        int right = maxSubArray(nums, mid + 1, high);
        int ll = mid - 1, lsum = 0, lmax = 0;
        while (ll >= low) {
            lsum += nums[ll--];
            if (lmax < lsum) {
                lmax = lsum;
            }
        }

        int rr = mid + 1, rsum = 0, rmax = 0;
        while (rr <= high) {
            rsum += nums[rr++];
            if (rmax < rsum) {
                rmax = rsum;
            }
        }
        return max({left, right, nums[mid] + lmax + rmax});
     }

    int maxSubArray(vector<int>& nums) {
       return maxSubArray(nums, 0, nums.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

