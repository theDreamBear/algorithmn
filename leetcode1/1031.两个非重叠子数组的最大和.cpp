/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
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
//#define One
#define Second
class Solution {
 public:
    // 计算区间和
    int getPartialSum(const vector<int> &sum, int i, int step) {
        int j = i + step;
        if (j > sum.size() - 1) {
            return 0;
        }
        return sum[j] - sum[i];
    }

#ifdef One
    // 复杂度 O(n^2)
    // 这个决定了最终复杂度
    // 这个可以优化
    int getAnsHelper(const vector<int> &nums, const vector<int> &sum, int firstLen, int secondLen) {
        int ans = INT_MIN;
        for (int first = 0; first + firstLen + secondLen <= nums.size(); first++) {
            int firstValue = getPartialSum(sum, first, firstLen);
            int secondMax = INT_MIN;
            for (int second = first + firstLen; second + secondLen <= nums.size(); ++second) {
                int secondValue = getPartialSum(sum, second, secondLen);
                secondMax = max(secondMax, secondValue);
            }
            ans = max(ans, firstValue + secondMax);
        }
        return ans;
    }

    int maxSumTwoNoOverlap1(vector<int> &nums, int firstLen, int secondLen) {
        vector<int> sum(nums.size() + 1);
        // partial_sum(nums.begin(), nums.end(), ++sum.begin());
        inclusive_scan(nums.begin(), nums.end(), ++sum.begin(), plus<>{});
        int ans = INT_MIN;
        // L 在左边
        ans = max(ans, getAnsHelper(nums, sum, firstLen, secondLen));
        // L 在右边
        ans = max(ans, getAnsHelper(nums, sum, secondLen, firstLen));
        return ans;
    }
#endif
    void calMax(const vector<int> &nums, const vector<int> &sum, vector<int>& sumMax, int len) {
        // 逆序求
        int curMax = INT_MIN;
        for (int cur = nums.size() - len; cur >= 0; --cur) {
            curMax = max(curMax, getPartialSum(sum, cur, len));
            sumMax[cur] = curMax;
        }
    }

    int getAnsHelperOptimize(const vector<int> &nums, const vector<int> &sum, const vector<int>& secondSumMax, int firstLen, int secondLen) {
        int ans = INT_MIN;
        for (int first = 0; first + firstLen + secondLen <= nums.size(); first++) {
            int firstValue = getPartialSum(sum, first, firstLen);
            int secondStartPos = first + firstLen;
            ans = max(ans, firstValue + secondSumMax[secondStartPos]);
        }
        return ans;
    }

    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        vector<int> sum(nums.size() + 1);
        // partial_sum(nums.begin(), nums.end(), ++sum.begin());
        inclusive_scan(nums.begin(), nums.end(), ++sum.begin(), plus<>{});

        vector<int> fisrtSumMax(nums.size());
        vector<int> secondSumMax(nums.size());

        calMax(nums, sum, fisrtSumMax, firstLen);
        calMax(nums, sum, secondSumMax, secondLen);
        int ans = INT_MIN;
        // L 在左边
        ans = max(ans, getAnsHelperOptimize(nums, sum, secondSumMax, firstLen, secondLen));
//        // L 在右边
        ans = max(ans, getAnsHelperOptimize(nums, sum, fisrtSumMax, secondLen, firstLen));
        return ans;
    }
};

// @lc code=end

