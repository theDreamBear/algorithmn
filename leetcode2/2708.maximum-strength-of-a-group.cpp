// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2708 lang=cpp
 * @lcpr version=30204
 *
 * [2708] 一个小组的最大实力值
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
    long long maxStrength1(vector<int>& nums) {
        // 前i 个选出的最大正数, 最大负数
        auto handler = [&](int i, int h) -> pair<bool, long long> {
            if (i < 0) {
                return {true, LLONG_MIN};
            }
            return {false, 0};
        };
        int n = nums.size();
        int cnt = count(nums.begin(), nums.end(), 0);
        long long dp[2][2];
        int ft = 0, st = 1;
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[ft][h];
        };
        for (int i = 0; i < n; i++) {
            // 最大整数
            if (nums[i] > 0) {
                dp[st][0] = get_v(i - 1, 0) != LLONG_MIN ? get_v(i - 1, 0) * nums[i]: nums[i];
                dp[st][1] = get_v(i - 1, 1) != LLONG_MIN ? get_v(i - 1, 1) * nums[i] : LLONG_MIN;
            } else if (nums[i] < 0) {
                dp[st][0] = max(get_v(i - 1, 0), get_v(i - 1, 1) != LLONG_MIN ? get_v(i - 1, 1) * nums[i]:  LLONG_MIN);
                dp[st][1] = min(get_v(i - 1, 1) != LLONG_MIN ? get_v(i - 1, 1): LLONG_MAX, get_v(i - 1, 0) != LLONG_MIN ?  get_v(i - 1, 0) * nums[i]:  nums[i]);
            } else {
                dp[st][0] = get_v(i - 1, 0);
                dp[st][1] = get_v(i - 1, 1);
            }
            swap(ft, st);
        }
        long long ans = max(dp[ft][0], dp[ft][1]);
        if (ans == LLONG_MIN) {
            return 0;
        }
        if (ans >= 0) {
            return ans;
        }
        if (cnt > 0) {
            return 0;
        }
        return ans;
    }

    long long maxStrength2(vector<int>& nums) {
        long long p = LLONG_MIN, n = LLONG_MAX;
        bool has = 0;
        for (auto v: nums) {
            if (v > 0) {
                long long np = max({p, (long long)v, p > 0 ? p * v : LLONG_MIN});
                long long nn = min({n, n < 0 ? n * v : LLONG_MAX});
                p = np;
                n = nn;
            } else if (v < 0) {
                long long np = max({p, n < 0 ? n * v: LLONG_MIN});
                long long nn = min({n, (long long)v, p > 0 ? p * v: LLONG_MAX});
                p = np;
                n = nn;
            } else {
                has = 1;
            }
        }
        if (p == LLONG_MIN and n == LLONG_MAX) {
            return 0;
        }
        // 没有最大值
        if (p == LLONG_MIN) {}

        if (n == LLONG_MAX) {
            n = 0;
        }
        auto ans = max(p, n);
        if (ans >= 0 || !has) {
            return ans;
        }
        return 0;
    }

    long long maxStrength(vector<int>& nums) {
        long long p = nums[0], n = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            long long v = nums[i];
            long long np = max({(long long)v, p, p * v, n * v});
            long long nn = min({(long long)v, n, n * v, p * v});
            p = np;
            n = nn;
        }
        return p;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxStrength
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [3,-1,-5,2,5,-9]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-5,-4]\n
// @lcpr case=end

 */
