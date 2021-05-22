/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <functional>
#include <unordered_set>
#include <utility>
#include <climits>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
    /*
        第一版直接回溯， 超时

    */
    int maxUncrossedLines1(vector<int>& nums1, vector<int>& nums2) {
        function<int(int, int, int, int)> backtrack =
            [&](int l1, int h1, int l2, int h2) -> int {
            int times = 0;
            for (int i = l1; i <= h1; ++i) {
                int num = nums1[i];
                for (int j = l2; j <= h2; ++j) {
                    if (nums2[j] == num) {
                        int left = 1 + backtrack(i + 1, h1, j + 1, h2);
                        if (left > times) {
                            times = left;
                        }
                    }
                }
            }
            return times;
        };
        return backtrack(0, nums1.size() - 1, 0, nums2.size() - 1);
    }

    void prepare(unordered_map<int, vector<int>>& hash,
                 const vector<int>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            hash[vec[i]].push_back(i);
        }
    }

    /*
        1 <= nums1.length <= 500
        1 <= nums2.length <= 500
        1 <= nums1[i], nums2[i] <= 2000

        500字符回溯法时间复杂度太高了
        增加备忘录通过
    */
    int maxUncrossedLines2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> hash;
        bool flag = nums1.size() < nums2.size();
        vector<int>*n1, *n2;
        if (flag) {
            n1 = &nums1;
            n2 = &nums2;
        } else {
            n1 = &nums2;
            n2 = &nums1;
        }
        prepare(hash, *n2);
        vector<vector<int>> dp(n1->size(), vector<int>(n2->size(), INT_MIN));
        function<int(int, int)> backtrack =
            [&](int l1, int l2) -> int {
            if (l1 >= n1->size() || l2 >= n2->size()) {
                return 0;
            }
            // 记忆化搜索
            if (dp[l1][l2] != INT_MIN) {
                return dp[l1][l2];
            }
            int times = 0;
            // 问题  dp[i][j] 出来了,  dp[i - 1][j], dp[i][j - 1] 应该也求出来了, 当前方法反而没出来, 造成重复计算
            for (int i = l1; i < n1->size(); ++i) {
                int num = (*n1)[i];
                if (hash.count(num) > 0) {
                    auto j = lower_bound(hash[num].begin(), hash[num].end(), l2) - hash[num].begin();
                    if (j >= hash[num].size()) {
                        continue;
                    }
                    int left = 1 + backtrack(i + 1, hash[num][j] + 1);
                    if (left > times) {
                        times = left;
                    }
                }
            }
            dp[l1][l2] = times;
            return times;
        };
        return backtrack(0, 0);
    }

      int maxUncrossedLines_2plus(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n ,INT_MIN));
        function<int(int, int)> backtrack =
            [&](int l1, int l2) -> int {
            if (l1 >= m|| l1 < 0|| l2 >= n || l2 < 0) {
                return 0;
            }
            // 记忆化搜索
            if (dp[l1][l2] != INT_MIN) {
                return dp[l1][l2];
            }
            int times = 0;
            // 问题  dp[i][j] 出来了,  dp[i - 1][j], dp[i][j - 1] 应该也求出来了, 当前方法反而没出来, 造成重复计算
            for (int i = l1; i < m; ++i) {
                for (int j = l2; j < n; ++j) {
                    if (nums1[i] == nums2[j]) {
                        dp[i][j] = 1 + backtrack(i - 1, j - 1);
                    } else {
                        dp[i][j] = max(backtrack(i - 1, j), backtrack(i, j - 1));
                    }
                }
            }
            return dp.back().back();
        };
        return backtrack(0, 0);
    }

    /*
        不能交换, 极值, 动态规划
        dp[i][j] 前 i, 前 j 的结果
        最长公共子序列问题
        滚动数组优化
    */

    int maxUncrossedLines_dynamic(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, INT_MIN));
        for (int i = 0; i <= nums2.size(); ++i) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= nums1.size(); ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp.back().back();
    }

    /*
        滚动数组
    */
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums2.size() + 1, 0);
        for (int i = 0; i < nums1.size(); ++i) {
            int prepre = 0;
            for (int j = 0; j < nums2.size(); ++j) {
                int pre =  dp[j + 1];
                if (nums1[i] == nums2[j]) {
                    dp[j + 1] = prepre + 1;
                } else {
                    dp[j + 1]= max(dp[j + 1], dp[j]);
                }
                prepre = pre;
            }
        }
        return dp.back();
    }


};
// @lc code=end

int main() {
    vector<int> n1 = {1, 2, 4};
    vector<int> n2 = {1, 4, 2};
    cout << Solution{}.maxUncrossedLines(n1, n2);
}