/*
 * @lc app=leetcode.cn id=2826 lang=cpp
 * @lcpr version=30204
 *
 * [2826] 将三个组排序
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
    int minimumOperations(vector<int>& nums) {
        auto handler = [&](int i, int h) -> pair<bool, int> {
            if (i < 0) {
                return {true, 0};
            }
            return {false, 0};
        };
        int n = nums.size();
        int dp[2][3];
        int ft = 0, st = 1;
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[ft][h];
        };
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                // 1
                dp[st][0] = get_v(i - 1, 0);
                // 2
                dp[st][1] = get_v(i - 1, 1) + 1;
                // 3
                dp[st][2] = get_v(i - 1, 2) + 1;
            } else if (nums[i] == 2) {
                dp[st][0] = get_v(i - 1, 0) + 1;
                // 2
                dp[st][1] = min(get_v(i - 1, 1), get_v(i - 1, 0));
                // 3
                dp[st][2] = get_v(i - 1, 2) + 1;
            } else {
                  // 1
                dp[st][0] = get_v(i - 1, 0) + 1;
                // 2
                dp[st][1] = get_v(i - 1, 1) + 1;
                // 3
                dp[st][2] = min({get_v(i - 1, 2), get_v(i - 1, 1), get_v(i - 1, 0)});
            }
            swap(ft, st);
        }
        return min({dp[ft][0], dp[ft][1], dp[ft][2]});
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,3,3]\n
// @lcpr case=end

 */
