/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=30122
 *
 * [213] 打家劫舍 II
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums.back();
        }
        int ans = 0;
        // 偷第一间房子
        int prepre = nums[0];
        int pre = prepre;
        for (int i = 2; i + 1 < n; i++) {
            int tmp = max(prepre + nums[i], pre);
            prepre = pre;
            pre = tmp;
        }
        ans = pre;
        // 不偷第一间屋子
        prepre = 0;
        pre = nums[1];
        for (int i = 2; i < n; i++) {
            int tmp = max(prepre + nums[i], pre);
            prepre = pre;
            pre = tmp;
        }
        return max(ans, pre);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

