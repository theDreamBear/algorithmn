/*
 * @lc app=leetcode.cn id=2771 lang=cpp
 * @lcpr version=30204
 *
 * [2771] 构造最长非递减子数组
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
    // 子数组不是子序列, 所以错了
    int maxNonDecreasingLength_wa(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp;
        for (int i = 0; i < nums1.size(); i++) {
            int mm = nums1[i], ma = nums2[i];
            if (mm > ma) {
                swap(mm, ma);
            }
            // 先操作大的
            auto it = upper_bound(dp.begin(), dp.end(), ma);
            if (it != dp.end()) {
                *it = ma;
            } else {
                dp.push_back(ma);
            }
            if (ma == mm) continue;
            it = upper_bound(dp.begin(), dp.end(), mm);
            if (it != dp.end()) {
                *it = mm;
            } else {
                dp.push_back(mm);
            }
        }
        return dp.size();
    }

    int maxNonDecreasingLength1(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][0] 以s1 结尾的最大子数组长度
        // dp[i][1] 以s2 结尾的最大子数组长度
        // dp[i][0] = max(nums1[i] >= nums1[i - 1] ? dp[i - 1][0] + 1 : 1, nums1[i] >= nums2[i - 1] ? dp[i - 1][1] + 1 : 1);
        // dp[i][1] = max(nums2[i] >= nums2[i - 1] ? dp[i - 1][1] + 1 : 1, nums2[i] >= nums1[i - 1] ? dp[i - 1][0] + 1 : 1);
        int n = nums1.size();
        int dp[2][2]{};
        dp[0][0] = 1, dp[0][1] = 1;
        int ft = 0, st = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            dp[st][0] = max(nums1[i] >= nums1[i - 1] ? dp[ft][0] + 1 : 1, nums1[i] >= nums2[i - 1] ? dp[ft][1] + 1 : 1);
            dp[st][1] = max(nums2[i] >= nums2[i - 1] ? dp[ft][1] + 1 : 1, nums2[i] >= nums1[i - 1] ? dp[ft][0] + 1 : 1);
            ans = max({ans, dp[st][0], dp[st][1]});
            swap(ft, st);
        }
        return ans;
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int dp[n][2];
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&& dfs, int i, int j)->int {
            if (i <= 0) return 1;
            if (dp[i][j] != -1) return dp[i][j];
            int res = 1;
            if (nums1[i] >= nums1[i - 1] and j == 0) {
                res = max(res, dfs(dfs, i - 1, 0) + 1);
            }
            if (nums2[i] >= nums2[i - 1] and j == 1) {
                res = max(res, dfs(dfs, i - 1, 1) + 1);
            }
            if (nums1[i] >= nums2[i - 1] and j == 0) {
                res = max(res, dfs(dfs, i - 1, 1) + 1);
            }
            if (nums2[i] >= nums1[i - 1] and j == 1) {
                res = max(res, dfs(dfs, i - 1, 0) + 1);
            }
            return dp[i][j] = res;
        };
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                ans = max(ans, dfs(dfs, i, j));
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1]\n[1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,1]\n[2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n[2,2]\n
// @lcpr case=end

 */

