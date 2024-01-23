/*
 * @lc app=leetcode.cn id=2765 lang=cpp
 * @lcpr version=30113
 *
 * [2765] 最长交替子数组
 */

// @lcpr-template-start
#include <numeric>
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
    /*
    2 <= nums.length <= 100
    1 <= nums[i] <= 10^4
    */
    int alternatingSubarray1(vector<int>& nums)
    {
        vector<int> adjDiff(nums.size());
        adjacent_difference(nums.begin(), nums.end(), adjDiff.begin());

        // 忽略第一个1， 因为这个1是原值， 不是diff
        auto it = find(adjDiff.begin() + 1, adjDiff.end(), 1);
        if (it == adjDiff.end()) {
            return -1;
        }
        int ans       = -1;
        int pos       = it - adjDiff.begin() + 1;
        int ct        = 2;
        int target[2] = {-1, 1};
        while (pos < adjDiff.size()) {
            // 连续
            if (adjDiff[pos] == target[ct % 2]) {
                pos++;
                ct++;
                continue;
            }
            // 取最大值
            ans = max(ans, ct);
            // 下一个区间
            it = find(adjDiff.begin() + pos, adjDiff.end(), 1);
            if (it == adjDiff.end()) {
                break;
            }
            // 初始化
            ct  = 2;
            pos = it - adjDiff.begin() + 1;
        }
        // 如果前面一直连续， 这里需要进行更新
        ans = max(ans, ct);
        return ans;
    }

    int alternatingSubarray(vector<int>& nums) {
        // 区间思维， 寻找每一个区间
        // 区间定义 【start, end)
        int ans = -1;
        int pos = 1;
        while (pos < nums.size()) {
            // 找第一个diff 1
            int i = pos;
            while (i < nums.size() && nums[i] - nums[i - 1] != 1) {
                i++;
            }
            if (i >= nums.size()) {
                break;
            }
            int start = i - 1;
            int end = i;
            // 扩展
            int target[2] = {-1, 1};
            while (end < nums.size() && nums[end] - nums[end - 1] == target[(end - start) % 2]) {
                end++;
            }
            // 更新
            ans = max(ans, end - start);
            pos = end;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,4,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6]\n
// @lcpr case=end

 */
