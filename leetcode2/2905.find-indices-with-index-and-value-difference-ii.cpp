/*
 * @lc app=leetcode.cn id=2905 lang=cpp
 * @lcpr version=30204
 *
 * [2905] 找出满足差值条件的下标 II
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
    // 枚举右维护左
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        // 枚举左边最大最小值
        int n = nums.size();
        int pmm = -1, pma = -1;
        int preMax = INT_MIN, preMin = INT_MAX;
        for (int i = indexDifference, j = 0; i < n and j < n; i++, j++) {
            // 本一轮更新
            if (nums[j] < preMin) {
                preMin = nums[j];
                pmm = j;
            }
            if (nums[j] > preMax) {
                preMax = nums[j];
                pma = j;
            }
            if (abs(nums[i] - preMin) >= valueDifference) {
                return {pmm, i};
            }
            if (abs(nums[i] - preMax) >= valueDifference) {
                return {pma, i};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,4,1]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n2\n4\n
// @lcpr case=end

 */

