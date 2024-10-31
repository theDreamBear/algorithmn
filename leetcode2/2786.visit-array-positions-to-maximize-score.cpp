/*
 * @lc app=leetcode.cn id=2786 lang=cpp
 * @lcpr version=30204
 *
 * [2786] 访问数组中的位置使分数最大
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
    long long maxScore(vector<int>& nums, int x) {
        auto handler = [&](int i, int h) -> pair<bool, long long> {
            if (i < 0) {
                // 起点固定了
                return {true, h == nums[0] % 2 ? 0: -x};
            }
            return {false, 0};
        };
        int n = nums.size();
        long long dp[n][2];
        int ft = 0, st = 1;
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[ft][h];
        };
        for (int i = 0; i < n; i++) {
            // 起点固定了
            if (nums[i] % 2 != 0) {
                dp[st][0] = get_v(i - 1, 0);
                dp[st][1] = max(get_v(i - 1, 1), get_v(i - 1, 0) - x) + nums[i];
            } else {
                dp[st][0] = max(get_v(i - 1, 0), get_v(i - 1, 1) - x) + nums[i];
                dp[st][1] = get_v(i - 1, 1);
            }
            swap(ft, st);
        }
        return max(dp[ft][0], dp[ft][1]);
    }

    long long maxScore1(vector<int>& nums, int x) {
        int n = nums.size();
        long long max_odd = 0, max_even = 0;
        //long long ans = 0;
        // 前置条件奇偶都是从0位置转移过来的， 保证这一点
        int i = 0;
        if (nums[i] & 1) {
            max_odd = nums[i];
            // 找到第一个偶数
            while (i + 1 < n and nums[i+1] & 1) max_odd += nums[++i];
            if (i + 1 < n) {
                max_even = max_odd + nums[++i] - x;
            }
        } else {
            max_even= nums[i];
            // 找到第一个偶数
            while (i + 1 < n and !(nums[i+1] & 1)) max_even += nums[++i];
            if (i + 1 < n) {
                max_odd = max_even + nums[++i] - x;
            }
        }
        for  (++i; i < n; i++) {
            if (nums[i] & 1) {
                max_odd = max(max_odd + nums[i] , max_even + nums[i]  - x);
            } else {
                max_even = max(max_even + nums[i] , max_odd + nums[i]  - x);
            }
        }
        return max(max_even, max_odd);
    }

    long long maxScore3(vector<int>& nums, int x) {
        int n = nums.size();
        long long max_odd = nums[0], max_even = nums[0];
        if (nums[0] & 1) {
            max_even -= x;
        } else {
            max_odd -= x;
        }
        for  (int i = 1; i < n; i++) {
            if (nums[i] & 1) {
                max_odd = max(max_odd + nums[i] , max_even + nums[i]  - x);
            } else {
                max_even = max(max_even + nums[i] , max_odd + nums[i]  - x);
            }
        }
        return max(max_even, max_odd);
    }

    // 倒着做
    long long maxScore2(vector<int>& nums, int x) {
        int n = nums.size();
        long long max_odd = 0, max_even = 0;
        for  (int i = n - 1; i >= 0l; i--) {
            if (nums[i] & 1) {
                max_odd = max(max_odd + nums[i] , max_even + nums[i]  - x);
            } else {
                max_even = max(max_even + nums[i] , max_odd + nums[i]  - x);
            }
        }
        return nums[0] & 1 ? max_odd : max_even;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,1,9,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,8]\n3\n
// @lcpr case=end

 */
