/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 * @lcpr version=30204
 *
 * [2576] 求出最多标记下标
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
    int maxNumOfMarkedIndices1(vector<int>& nums) {
        ranges::sort(nums);
        // 
        int n = nums.size();
        int ans = 0;
        for (int i = 0, j = n / 2; i < n / 2 and j < n; i++) {
            while (j < n and nums[i] * 2 > nums[j]) j++;
            if (j < n and nums[i] * 2 <= nums[j]) {
                ans += 2;
                j++;
            }
        }
        return ans;
    }
    // 二分枚举
    int maxNumOfMarkedIndices(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int low = 0, high = n / 2;
        auto check = [&](int mid) {
            int l = mid - 1, r = n - 1;
            for (; l >= 0; l--, r--) {
                if (nums[l] * 2 > nums[r]) {
                    return false;
                }
            }
            return true;
        };
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (check(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        if (check(high)) {
            return high * 2;
        }
        return low * 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [9,2,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,8]\n
// @lcpr case=end

 */

