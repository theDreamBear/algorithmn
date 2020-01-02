/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.40%)
 * Likes:    1442
 * Dislikes: 0
 * Total Accepted:    136.4K
 * Total Submissions: 281.7K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    /**
     *  1. n * n;
     * 
     * 
     * 
     * 
     * **/
    int maxSubArray_N_N(vector<int>& nums) {
        int globalMax = nums[0];
        for (int left = 0; left < nums.size(); ++left) {
            int localMax = 0;
            for (int right = left; right < nums.size(); ++right) {
                localMax += nums[right];
                if (localMax > globalMax) {
                    globalMax = localMax;
                }
            }
        }
        return globalMax;
    }

    /**
     *  2. 
     * 
     * 
     * 
     * ***/
    int maxSubArray1(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        #define XXX
        #ifdef MY
        int globalMax = nums[0];
        int localMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            // 和 XXX 比较我们可以发现, 当 localMax >= 0时若 localMax + nums[i] <= 0的时候, nums[i] 不可能是最大值
            // 故没必要让 sum = nums[i], 故可以直接 localMax += nums[i];
            if (localMax < 0 || localMax + nums[i] <= 0) {
                localMax = nums[i];
            } else {
                if (localMax + nums[i] > 0) {
                    localMax += nums[i];
                }
            }
            if (localMax > globalMax) {
                globalMax = localMax;
            }
            //cout << localMax << ": " << globalMax << endl;
        }
        return globalMax;
        #endif

        #ifdef DEBUG
        int globalMax = -0x7fffffff, localMax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            localMax += nums[i];
            if (localMax > globalMax) {
                globalMax = localMax;
            }
            if (localMax < 0) {
                localMax = 0;
            }
        }
        return globalMax;
        #endif // DEBUG

        #ifdef XXX
        int ans = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (sum > 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
        #endif
    }

    // 归并
    int maxSubArrayHelper(vector<int>& nums, int low, int high) {
        if (low > high) {
            return -0x7fffffff;
        }
        if (low == high) {
            return nums[low];
        }
        int mid = low + (high - low) / 2;
        int maxValue = nums[mid];
        int localLeft = 0;
        int maxLeft = 0;
        // 左边
        for(int i = mid - 1; i >= low; --i) {
            localLeft += nums[i];
            if (localLeft > maxLeft) {
                maxLeft = localLeft;
            }
        }
        int localRight = 0;
        int maxRight = 0;
        // 右边
        maxRight = 0;
        for (int i = mid + 1; i <= high; ++i) {
            localRight += nums[i];
            if (localRight > maxRight) {
                maxRight = localRight;
            }
        }
        maxValue += (maxLeft + maxRight);
        maxValue = max(maxValue, maxSubArrayHelper(nums, low, mid - 1));
        maxValue = max(maxValue, maxSubArrayHelper(nums, mid + 1, high));
        return maxValue;
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v);
}
