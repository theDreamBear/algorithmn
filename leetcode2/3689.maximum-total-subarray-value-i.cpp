/*
 * @lc app=leetcode.cn id=3689 lang=cpp
 * @lcpr version=30204
 *
 * [3689] 最大子数组总值 I
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
    // 和区间里面的最大 最小值有关
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [mm, mx] = ranges::minmax(nums);
        return (long long)(mx - mm) * k;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5,1]\n3\n
// @lcpr case=end

 */

