/*
 * @lc app=leetcode.cn id=面试题 17.16 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 17.16] 按摩师
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
    int massage(vector<int>& nums) {
        // 其实就是打家劫舍问题
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int prepre = nums[0], pre = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int x = max(prepre + nums[i], pre);
            prepre = pre;
            pre = x;
        }
        return pre;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,4,5,3,1,1,3]\n
// @lcpr case=end

 */

