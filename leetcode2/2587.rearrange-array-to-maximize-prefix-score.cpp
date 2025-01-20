/*
 * @lc app=leetcode.cn id=2587 lang=cpp
 * @lcpr version=30204
 *
 * [2587] 重排数组以得到最大前缀分数
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& nums) {
        ranges::sort(nums, greater<>{});
        if (nums[0] <= 0) return 0;
        long long cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur += nums[i];
            if (cur <= 0) return i;
        }
        return nums.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,-1,0,1,-3,3,-3]\n
// @lcpr case=end

// @lcpr case=start
// [-2,-3,0]\n
// @lcpr case=end

 */

