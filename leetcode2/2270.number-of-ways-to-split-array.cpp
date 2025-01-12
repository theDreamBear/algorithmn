/*
 * @lc app=leetcode.cn id=2270 lang=cpp
 * @lcpr version=30204
 *
 * [2270] 分割数组的方案数
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
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long total = accumulate(nums.begin(), nums.end(), 0ll);
        long long sum = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            sum += nums[i];
            total -= nums[i];
            if (sum >= total) ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,4,-8,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,1,0]\n
// @lcpr case=end

 */

