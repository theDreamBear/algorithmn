/*
 * @lc app=leetcode.cn id=3737 lang=cpp
 * @lcpr version=30204
 *
 * [3737] 统计主要元素子数组数目 I
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
/**
 * @brief 
 *  滑动窗口 单调性: 增加一定不满足, 收缩来满足
 * 这个题, 增加不一定不满足
 * @param nums 
 * @param target 
 * @return int 
 */
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int ct  = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == target) ct++;
                if (ct * 2 > (j - i + 1)) { 
                    ans++;
                }
            }
        }
        return ans;
    }

    // -1 1 1 -1
    // 0 -1 0 1 0
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

 */

