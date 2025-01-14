/*
 * @lc app=leetcode.cn id=3065 lang=cpp
 * @lcpr version=30204
 *
 * [3065] 超过阈值的最少操作数 I
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
    int minOperations1(vector<int>& nums, int k) {
        ranges::sort(nums);
        return ranges::lower_bound(nums, k) - nums.begin();
    }

    int minOperations(vector<int>& nums, int k) {
        return ranges::count_if(nums, [&](int v) {
            return v < k;
        });
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,11,10,1,3]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,4,9]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,4,9]\n9\n
// @lcpr case=end

 */

