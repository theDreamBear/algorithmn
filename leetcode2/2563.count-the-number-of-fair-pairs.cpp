/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 * @lcpr version=30204
 *
 * [2563] 统计公平数对的数目
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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        // 
        int n = nums.size();
        long long ans = 0;
        long long sum = 0;
        // 两个数
        for (int i = 0; i < n; i++) {
            auto lt = ranges::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto rt = ranges::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            ans += (long long)(rt - lt);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,7,4,4,5]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,7,9,2,5]\n11\n11\n
// @lcpr case=end

 */

