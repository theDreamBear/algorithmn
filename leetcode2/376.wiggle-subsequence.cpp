/*
 * @lc app=leetcode.cn id=376 lang=cpp
 * @lcpr version=30204
 *
 * [376] 摆动序列
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
    int wiggleMaxLength1(vector<int>& nums) {
        auto handler = [&](int i, int h) -> pair<bool, int> {
            if (i < 0) {
                return {true, 0};
            }
            return {false, 0};
        };
        int n = nums.size();
        // 0, 差为正数
        // 1, 差为负数
        int dp[n][2];
        auto get = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[i][h];
        };
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 1;
                dp[i][1] = 1;
            } else {
                if (nums[i] > nums[i - 1]) {
                    dp[i][0] = max(get(i - 1, 0), get(i - 1, 1) + 1);
                    dp[i][1] = get(i - 1, 1);
                } else if (nums[i] < nums[i - 1]) {
                    dp[i][0] = get(i - 1, 0);
                    dp[i][1] = max(get(i - 1, 0) + 1, get(i - 1, 1));
                } else {
                    dp[i][0] = get(i - 1, 0);
                    dp[i][1] = get(i - 1, 1);
                }
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }

    int wiggleMaxLength2(vector<int>& nums) {
        auto handler = [&](int i, int h) -> pair<bool, int> {
            if (i < 0) {
                return {true, 0};
            }
            return {false, 0};
        };
        int n = nums.size();
        // 0, 差为正数
        // 1, 差为负数
        int dp[2][2];
        int ft = 0, st = 1;
        auto get = [&](int i, int h) {
            return dp[ft][h];
        };
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[st][0] = 1;
                dp[st][1] = 1;
            } else {
                if (nums[i] > nums[i - 1]) {
                    dp[st][0] = max(get(i - 1, 0), get(i - 1, 1) + 1);
                    dp[st][1] = get(i - 1, 1);
                } else if (nums[i] < nums[i - 1]) {
                    dp[st][0] = get(i - 1, 0);
                    dp[st][1] = max(get(i - 1, 0) + 1, get(i - 1, 1));
                } else {
                    dp[st][0] = get(i - 1, 0);
                    dp[st][1] = get(i - 1, 1);
                }
            }
            swap(ft, st);
        }
        return max(dp[ft][0], dp[ft][1]);
    }

    int wiggleMaxLength(vector<int>& nums) {
        int down = 1, up = 1;
        int n = nums.size(); 
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,4,9,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,17,5,10,13,15,10,5,16,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9]\n
// @lcpr case=end

 */
