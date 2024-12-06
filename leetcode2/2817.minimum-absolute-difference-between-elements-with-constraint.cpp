/*
 * @lc app=leetcode.cn id=2817 lang=cpp
 * @lcpr version=30204
 *
 * [2817] 限制条件下元素之间的最小绝对差
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
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int> ms;
        for (int i = x; i < nums.size(); i++) {
            ms.insert(nums[i]);
        }
        int ans = INT_MAX;
        for (int i = 0, j = x; i + x < nums.size(); i++, j++) {
            auto it = ms.lower_bound(nums[i]);
            if (it != ms.end()) {
                ans = min(ans, *it - nums[i]);
            }
            if (it != ms.begin()) {
                ans = min(ans, nums[i] - *prev(it));
            }
            ms.extract(nums[j]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,3,2,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,3,2,10,15]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n3\n
// @lcpr case=end

 */

