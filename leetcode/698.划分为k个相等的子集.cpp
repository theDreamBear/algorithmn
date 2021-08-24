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

    bool backTrack(vector<int> &data, int pos, int now, const int sum) {
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
                if (backTrack(data, pos + 1, cur, sum)) {
                    return true;
                }
            }
            swap(data[i], data[pos]);
        }
        return false;
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
        // 深度 暴力如何得到呢
        // 全排列
        return backTrack(nums, 0, 0, subSum);
    }
};
// @lc code=end

