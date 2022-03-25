/*
 * @lc app=leetcode.cn id=1995 lang=cpp
 *
 * [1995] 统计特殊四元组
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
    // 纯暴力
    int countQuadruplets1(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i + 3 < nums.size(); i++) {
            for (int j = i + 1; j + 2 < nums.size(); j++) {
                for (int k = j + 1; k + 1 < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    for (int m = k + 1; m < nums.size(); m++) {
                        if (sum == nums[m]) {
                            ++ans;
                        }
                    }
                }
            }
        }
        return ans;
    }

    int countQuadruplets2(vector<int> &nums) {
        int ans = 0;
        unordered_map<int, vector<int>> indexes;
        for (int i = 0; i < nums.size(); i++) {
            indexes[nums[i]].push_back(i);
        }
        for (int i = 0; i + 3 < nums.size(); i++) {
            for (int j = i + 1; j + 2 < nums.size(); j++) {
                for (int k = j + 1; k + 1 < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (indexes.count(sum) > 0) {
                        ans += (indexes[sum].end() - upper_bound(indexes[sum].begin(), indexes[sum].end(), k));
                    }
                }
            }
        }
        return ans;
    }

    int countQuadruplets3(vector<int> &nums) {
        int ans = 0;
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); i++) {
            indexes[nums[i]]++;
        }
        for (int i = 0; i + 3 < nums.size(); i++) {
            --indexes[nums[i]];
            for (int j = i + 1; j + 2 < nums.size(); j++) {
                --indexes[nums[i]];
                for (int k = j + 1; k + 1 < nums.size(); k++) {
                    --indexes[nums[i]];
                    int sum = nums[i] + nums[j] + nums[k];
                    if (indexes.count(sum) > 0) {
                        ans += indexes[sum];
                    }
                }
            }
        }
        return ans;
    }

    int countQuadruplets4(vector<int> &nums) {
        int ans = 0;
        unordered_map<int, int> cts;
        for (int c = nums.size() - 2; c >= 2; c--) {
            ++cts[nums[c + 1]];
            for (int b = c - 1; b >= 1; --b) {
                for (int a = b - 1; a >= 0; --a) {
                    int sum = nums[a] + nums[b] + nums[c];
                    if(cts.count(sum) > 0) {
                        ans += cts[sum];
                    }
                }
            }
        }
        return ans;
    }

    // O(n^2)
    int countQuadruplets5(vector<int> &nums) {
        int ans = 0;
        unordered_map<int, int> cts;
        for (int b = nums.size() - 3; b >= 1; b--) {
            for (int d = b + 2; d < nums.size(); d++) {
                ++cts[nums[d] - nums[b + 1]];
            }
            for (int a = 0; a < b; a++) {
                int sum = nums[a] + nums[b];
                if (cts.count(sum) > 0) {
                    ans += cts[sum];
                }
            }
        }
        return ans;
    }

    int countQuadruplets(vector<int> &nums) {
        int ans = 0;
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(110, vector<int>(4)));
        // 定义 dp[i][j][k] 前 i 个数, 和为 j, 取的数字个数为 k 时候的方案值
        // dp[0][0][0] = 1;
        // dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - nums[i - 1]][k - 1]
        // ans = dp[i][nums[i - 1]][3];
       // dp[0][0][0] = 1;
        for (int i = 0; i < n + 1; i++) {
            dp[i][0][0] = 1;
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j <= 100; j++) {
                for (int k = 1; k < 4; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= nums[i - 1]) {
                        dp[i][j][k] += dp[i - 1][j - nums[i - 1]][k - 1];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ans += dp[i + 1][nums[i]][3];
        }
        return ans;
    }
};
// @lc code=end

