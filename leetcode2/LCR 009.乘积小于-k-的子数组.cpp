/*
 * @lc app=leetcode.cn id=LCR 009 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 009] 乘积小于 K 的子数组
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
    int numSubarrayProductLessThanK_暴力(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int multy = 1;
            for (int j = i; j < nums.size(); j++) {
                multy *= nums[j];
                if (multy >= k) {
                    break;
                }
                ans++;
            }
        }
        return ans;
    }

    int numSubarrayProductLessThanK_bad(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int ans = 0;
        int j = 0;
        int multy = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                multy /= nums[i - 1];
                if (multy >= k) {
                    ans += (j - i);
                    continue;
                }
                ans += j - i;
                if (j < nums.size()) {
                    ans++;
                }
                if (j + 1 < nums.size()) {
                    j++;
                }
            }
            for (; j < nums.size(); j++) {
                multy *= nums[j];
                if (multy >= k) {
                    break;
                }
                ans++;
            }
        }
        return ans;
    }

    int numSubarrayProductLessThanK_slidingWindows(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int ans = 0;
        // 滑动窗口
        int left = 0, right = 0, product = 1;
        // [left, right), 乘积为product
        for (; right < nums.size(); right++) {
            product *= nums[right];
            while (left <= right and product >= k) {
                product /= nums[left];
                left++;
            }
            // 如果lleft > right 则结果为0
            ans += (right - left + 1);
        }
        return ans;
    }

    bool can(int i, int mid, vector<long long>& prefix, int k) {
        return prefix[mid] / prefix[i] < k;
    }

    int numSubarrayProductLessThanK_binary_almost(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        // 二分
        int ans = 0;
        // 直接使用前缀和会超出long long的范围
        vector<long long> prefix(nums.size() + 1, 1);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] * nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            // 找到 < k 的最大
            // [i, mid] 实际代表着[i, mid - 1] 的乘积 = prefix[mid] / prefix[i]
            int low = 0, high = nums.size();
            while (low + 1 < high) {
                int mid = low + (high - low) / 2;
                if (can(i, mid, prefix, k)) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            if (can(i, high, prefix, k)) {
                ans += high - i;
            } else {
                ans += low - i;
            }
        }
        return ans;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        // 二分
        int ans = 0;
        // 直接使用前缀和会超出long long的范围
        vector<double> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + log(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            // 找到 < k 的最大
            // [i, mid] 实际代表着[i, mid - 1] 的乘积 = prefix[mid] / prefix[i]
            int low = 0, high = nums.size();
            while (low + 1 < high) {
                int mid = low + (high - low) / 2;
                // doule 的精度问题， double 只有15位有效数字
                // 所以需要使用容积
                if (prefix[mid] - prefix[i] + 1e-14 < log(k)) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            // 1e-1 是为了防止浮点数的精度问题
            if (prefix[high] - prefix[i] + 1e-14 < log(k)) {
                ans += high - i;
            } else {
                ans += low - i;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */

