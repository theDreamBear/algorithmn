/*
 * @lc app=leetcode.cn id=2239 lang=cpp
 * @lcpr version=30204
 *
 * [2239] 找到最接近 0 的数字
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
    int findClosestNumber1(vector<int>& nums) {
        int ans = nums[0];
        for (auto v: nums) {
            if (abs(v) < abs(ans) or abs(v) == abs(ans) and v > ans) {
                ans = v;
            }
        }
        return ans;
    }

    int findClosestNumber(vector<int>& nums) {
        return ranges::min(nums, {}, [](int x) {
            return pair(abs(x), -x);
        });
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-4,-2,1,4,8]\n
// @lcpr case=end

// @lcpr case=start
// [2,-1,1]\n
// @lcpr case=end

 */

