// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3326 lang=cpp
 * @lcpr version=30204
 *
 * [3326] 使数组非递减的最少除法操作次数
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
// 预处理上
const int MX = 1'000'001;
int       dp[MX];

auto init = [] {
    for (int i = 2; i < MX; i++) {
        if (!dp[i]) {
            for (int j = i; j < MX; j += i) {
                if (!dp[j]) {
                    dp[j] = i;
                }
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minOperations1(vector<int>& nums) {
        int ans = 0;
        int n   = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                nums[i] = dp[nums[i]];
                if (nums[i] > nums[i + 1]) {
                    return -1;
                }
                ans++;
            }
        }
        return ans;
    }

    // 超时 1e6  sqrt(n) * n 会超时
    int minOperations1_ttl(vector<int>& nums) {
        // 1 没有真因数
        // 2 不能变小导致-1
        // 算出每个数的最大真因数
        // nlgn的解法
        // 预处理nlgn
        int         ma = ranges::max(nums);
        vector<int> dp(ma + 1);
        // 质数都不能减少都为-1
        for (int i = 2; i <= ma; i++) {
            if (!dp[i]) {
                dp[i] = -1;
            }
            for (int j = i + i; j <= ma; j += i) {
                if (!dp[j]) {
                    dp[j] = i;
                }
            }
        }
        int ans = 0;
        while (true) {
            bool ok = true;
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] > nums[i + 1]) {
                    ok = false;
                    while (nums[i] > nums[i + 1]) {
                        if (dp[nums[i]] == -1)
                            return -1;
                        nums[i] = dp[nums[i]];
                        ++ans;
                    }
                }
            }
            if (ok) {
                break;
            }
        }
        return ans;
    }

    // 因为每个数替换一遍都会变成质数, 所以每个数只需要操作一遍, 如果前面的数操作过了,但出现了递减, 就返回-1
    // 还是超时, 所以问题还是出在筛选上
    // 逆序
    int minOperations_tt2(vector<int>& nums) {
        // 1 没有真因数
        // 2 不能变小导致-1
        // 算出每个数的最大真因数
        // nlgn的解法
        // 预处理nlgn
        int         ma = ranges::max(nums);
        vector<int> dp(ma + 1);
        // 质数都不能减少都为-1
        for (int i = 2; i <= ma; i++) {
            if (!dp[i]) {
                dp[i] = -1;
            }
            for (int j = i + i; j <= ma; j += i) {
                if (!dp[j]) {
                    dp[j] = i;
                }
            }
        }
        int ans = 0;
        while (true) {
            bool ok = true;
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] > nums[i + 1]) {
                    ok = false;
                    while (nums[i] > nums[i + 1]) {
                        if (dp[nums[i]] == -1)
                            return -1;
                        nums[i] = dp[nums[i]];
                        if (i > 0 and dp[nums[i - 1]] == -1 and nums[i - 1] > nums[i])
                            return -1;
                        ++ans;
                    }
                }
            }
            if (ok) {
                break;
            }
        }
        return ans;
    }

    // 还是超时了, 问题还是应该将预处理变成全局处理
    int minOperations_tt12(vector<int>& nums) {
        // 1 没有真因数
        // 2 不能变小导致-1
        // 算出每个数的最大真因数
        // nlgn的解法
        // 预处理nlgn
        int         ma = ranges::max(nums);
        vector<int> dp(ma + 1);
        // 质数都不能减少都为-1
        for (int i = 2; i <= ma; i++) {
            if (!dp[i]) {
                dp[i] = i;
            }
            for (int j = i + i; j <= ma; j += i) {
                if (!dp[j]) {
                    dp[j] = i;
                }
            }
        }
        int n = nums.size();
        int ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                nums[i] = dp[nums[i]];
                if (nums[i] > nums[i + 1]) {
                    return -1;
                }
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minOperations
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [25,7]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */
