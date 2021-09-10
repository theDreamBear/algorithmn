/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
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
constexpr int MAX_N = 1000;
constexpr int MAX_M = 51;
int dp[MAX_N][MAX_M];

const static int MAX_T = 1001;
int ma[MAX_T];
int x = 0;

class Solution {
 public:
    int splitArrayHelper(const vector<int> &nums, const vector<int> &suff, int j, int m) {
        if (dp[j][m] != -1) {
            return dp[j][m];
        }
        if (j + 1 < m) {
            return -1;
        }
        if (m == 0) {
            return 0;
        }
        if (m == 1) {
            // 优化1 提升
            return suff[j + 1];
        }
        if (j + 1 == m) {
            // 优化二求 区间的最大值
            // 提前算出来
            //return dp[i][j][m] = *max_element(nums.begin() + i, nums.begin() + j + 1);
            return ma[j];
        }
        dp[j][m] = INT_MAX;
        int sum = 0;
        for (int k = j - 1; k >= 0; k--) {
            int left = splitArrayHelper(nums, suff, k, m - 1);
            sum += nums[k + 1];
            if (left != -1) {
                dp[j][m] = min(dp[j][m], max(left, sum));
                if (left < sum) {
                    break;
                }
            }
        }
        return dp[j][m];
    }

    void init_max(const vector<int> &nums) {
        memset(ma, 0, sizeof ma);
        ma[0] = nums[0];
        for (int j = 1; j < nums.size(); j++) {
            ma[j] = max(ma[j - 1], nums[j]);
        }
    }

    int splitArray(vector<int> &nums, int m) {
        memset(dp, -1, sizeof(dp));
        vector<int> suff(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            suff[i + 1] = suff[i] + nums[i];
        }
        init_max(nums);
        return splitArrayHelper(nums, suff, nums.size() - 1, m);
    }
};


//class Solution2 {
// public:
//    int splitArrayHelper(const vector<int> &nums, const vector<int> &suff, int i, int j, int m) {
//        if (++x % 10000 == 0) {
//            cout << x << endl;
//        }
//        if (dp[i][j][m] != -1) {
//            return dp[i][j][m];
//        }
//        if (i > j || j - i + 1 < m) {
//            return -1;
//        }
//        if (m == 0) {
//            return 0;
//        }
//        if (m == 1) {
//            // 优化1 提升
//            return suff[j + 1] - suff[i];
//        }
//        if (i - i + 1 == m) {
//            // 优化二求 区间的最大值
//            // 提前算出来
//            //return dp[i][j][m] = *max_element(nums.begin() + i, nums.begin() + j + 1);
//            return ma[i][j];
//        }
//        dp[i][j][m] = INT_MAX;
//        for (int k = i; k < j; k++) {
//            for (int t = 1; t < m; t++) {
//                int left = splitArrayHelper(nums, suff, i, k, t);
//                int right = splitArrayHelper(nums, suff, k + 1, j, m - t);
//                if (left != -1 && right != -1) {
//                    int v = min(dp[i][j][m], max(left, right));
//                    dp[i][j][m] = v;
//                } else {
//                    if (right == -1) {
//                        break;
//                    }
//                }
//            }
//        }
//        return dp[i][j][m];
//    }
//
//    void init_max(const vector<int> &nums) {
//        memset(ma, 0, sizeof ma);
//        for (int i = 0; i < nums.size(); i++) {
//            ma[i][i] = nums[i];
//            for (int j = i + 1; j < nums.size(); j++) {
//                ma[i][j] = max(ma[i][j - 1], nums[j]);
//            }
//        }
//    }
//
//    int splitArray(vector<int> &nums, int m) {
//        memset(dp, -1, sizeof(dp));
//        vector<int> suff(nums.size() + 1);
//        for (int i = 0; i < nums.size(); i++) {
//            suff[i + 1] = suff[i] + nums[i];
//        }
//        init_max(nums);
//        return splitArrayHelper(nums, suff, 0, nums.size() - 1, m);
//    }
//};
//
//class Solution1 {
// public:
//    int splitArrayHelper(const vector<int> &nums, int i, int j, int m) {
//        if (dp[i][j][m] != -1) {
//            return dp[i][j][m];
//        }
//        if (i > j || j - i + 1 < m) {
//            return -1;
//        }
//        if (m == 0) {
//            return 0;
//        }
//        if (m == 1) {
//            return accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
//        }
//        if (i - i + 1 == m) {
//            return dp[i][j][m] = *max_element(nums.begin() + i, nums.begin() + j + 1);
//        }
//        dp[i][j][m] = INT_MAX;
//        for (int k = i; k < j; k++) {
//            for (int t = 1; t < m; t++) {
//                int left = splitArrayHelper(nums, i, k, t);
//                int right = splitArrayHelper(nums, k + 1, j, m - t);
//                if (left != -1 && right != -1) {
//                    int v = min(dp[i][j][m], max(left, right));
//                    dp[i][j][m] = v;
//                }
//            }
//        }
//        return dp[i][j][m];
//    }
//
//    int splitArray(vector<int> &nums, int m) {
//        memset(dp, -1, sizeof(dp));
//        return splitArrayHelper(nums, 0, nums.size() - 1, m);
//    }
//};

// @lc code=end

