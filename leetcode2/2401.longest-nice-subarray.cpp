/*
 * @lc app=leetcode.cn id=2401 lang=cpp
 * @lcpr version=30204
 *
 * [2401] 最长优雅子数组
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
    int longestNiceSubarray(vector<int>& nums) {
        // 滑动窗口
        int ans = 0;
        for (int left = 0, right = 0, mask = 0; right < nums.size(); right++) {
            while ((mask & nums[right])) {
                mask ^= nums[left++];
            }
            //if ((mask & nums[right]) == 0) {
            ans = max(ans, right - left + 1);
            mask ^= nums[right];
            //}
        }
        return ans;
    }

    int longestNiceSubarray_暴力可行(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) { // 枚举子数组右端点 i
            int or_ = 0, j = i;
            while (j >= 0 && (or_ & nums[j]) == 0) // nums[j] 与子数组中的任意元素 AND 均为 0
                or_ |= nums[j--]; // 加到子数组中
            ans = max(ans, i - j);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,8,48,10]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,5,11,13]\n
// @lcpr case=end

 */

