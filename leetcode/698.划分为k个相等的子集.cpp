/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
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
constexpr int MAX_N = 1 << 16;

class Solution {
public:
    bool checkSum(const vector<int> &data, const int sum, int pos) {
        int now = 0;
        for (int i = 0; i <= pos; i++) {
            int temp = now + data[i];
            if (temp < sum) {
                now = temp;
                continue;
            }
            if (temp == sum) {
                now = 0;
                continue;
            }
            return false;
        }
        return true;
    }

    bool backTrack1(vector<int> &data, int pos, int now, const int sum) {
        if (pos >= data.size()) {
            return true;
        }
        for (int i = pos; i < data.size(); i++) {
            swap(data[i], data[pos]);
            int cur = (now + data[pos]);
            if (cur <= sum) {
                if (cur == sum) {
                    cur = 0;
                }
                if (backTrack1(data, pos + 1, cur, sum)) {
                    return true;
                }
            }
            swap(data[i], data[pos]);
        }
        return false;
    }

    bool canPartitionKSubsets1(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        int subSum = sum / k;
        sort(nums.begin(), nums.end());
        if (nums.back() > subSum) {
            return false;
        }
        // 深度 暴力如何得到呢
        // 全排列
        return backTrack1(nums, 0, 0, subSum);
    }

    bool backtrack2(vector<int> &nums, vector<bool> &used, int begin, int k, int sum, int target) {
        if (k == 1) {
            return true;
        }
        if (sum == target) {
            return backtrack2(nums, used, nums.size() - 1, k - 1, 0, target);
        }
        for (int i = begin; i >= 0; i--) {
            if (used[i] || sum + nums[i] > target) {
                continue;
            }
            used[i] = true;
            if (backtrack2(nums, used, i - 1, k, sum + nums[i], target)) {
                return true;
            }
            used[i] = false;
            while (i > 0 && nums[i - 1] == nums[i]) {
                --i;
            }
        }
        return false;
    }

    bool canPartitionKSubsets2(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        int subSum = sum / k;
        sort(nums.begin(), nums.end(), greater<>{});
        if (nums.front() > subSum) {
            return false;
        }
        // 深度 暴力如何得到呢
        // 全排列
        vector<bool> used(nums.size());
        return backtrack2(nums, used, nums.size() - 1, k, 0, subSum);
    }

    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        int subSum = sum / k;
        sort(nums.begin(), nums.end());
        if (nums.back() > subSum) {
            return false;
        }
        int n = nums.size();
        int len = 1 << n;
        vector<int> dp(len);
        vector<int> total(len);
        vector<bool> used(n);

        dp[0] = true;
        for (int mask = 0; mask < len; mask++) {
            if (!dp[mask]) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (mask & (0x1 << i)) {
                    continue;
                }
                int next = mask | (0x1 << i);
                if (dp[next]) {
                    continue;
                }
                if (total[mask] + nums[i] > subSum) {
                    break;
                }
                total[next] = (total[mask] + nums[i]) % subSum;
                dp[next] = true;
            }
        }
        return dp[len - 1];
    }

};
// @lc code=end

