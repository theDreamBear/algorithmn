/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 * @lcpr version=30122
 *
 * [1749] 任意子数组和的绝对值的最大值
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
    int maxAbsoluteSum1(vector<int>& nums) {
        int ans = nums[0];
        int max_val = abs(nums[0]);
        // 正数
        for (int i = 1; i < nums.size(); i++) {
            if (ans <= 0) {
                ans = nums[i];
            } else {
                ans += nums[i];
            }
            max_val = max(max_val, ans);
        }
        // 负数
        ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (ans >= 0) {
                ans = nums[i];
            } else {
                ans += nums[i];
            }
            max_val = max(max_val, abs(ans));
        }
        return max_val;
    }

    int maxAbsoluteSum2(vector<int>& nums) {
        int max_val = abs(nums[0]);
        int p = nums[0], neg = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (p <= 0) {
                p = nums[i];
            } else {
                p += nums[i];
            }
            if (neg >= 0) {
                neg = nums[i];
            } else {
                neg += nums[i];
            }
            max_val = max({max_val, p, abs(neg)});
        }
        return max_val;
    }

    int maxAbsoluteSum3(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_v(n), min_v(n);
        max_v[0] = min_v[0] = nums[0];
        for (int i = 1; i < n; i++) {
            max_v[i] = min_v[i] = nums[i];
            if (max_v[i - 1] > 0) {
                max_v[i] += max_v[i - 1];
            }
            if (min_v[i - 1] < 0) {
                min_v[i] += min_v[i - 1];
            }
        }
        return max(*max_element(max_v.begin(), max_v.end()), -*min_element(min_v.begin(), min_v.end()));
    }

    /*
        前缀和的解法很优雅
    */
    int maxAbsoluteSum(vector<int>& nums) {
        int s = 0, mx = 0, mn = 0;
        for (auto v : nums) {
            s += v;
            mx = max(mx, s);
            mn = min(mn, s);
        }
        return mx - mn;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-3,2,3,-4]\n
// @lcpr case=end

// @lcpr case=start
// [2,-5,1,-4,3,-2]\n
// @lcpr case=end

 */

