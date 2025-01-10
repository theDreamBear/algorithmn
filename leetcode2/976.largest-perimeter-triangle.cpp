/*
 * @lc app=leetcode.cn id=976 lang=cpp
 * @lcpr version=30204
 *
 * [976] 三角形的最大周长
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
    int largestPerimeter(vector<int>& nums) {
        ranges::sort(nums, greater<>{});
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) return nums[i] + nums[i + 1] + nums[i + 2];
        }        
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,10]\n
// @lcpr case=end

 */

