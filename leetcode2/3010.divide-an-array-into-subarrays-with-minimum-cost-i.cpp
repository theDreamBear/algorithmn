/*
 * @lc app=leetcode.cn id=3010 lang=cpp
 * @lcpr version=30204
 *
 * [3010] 将数组分成最小总代价的子数组 I
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
    int minimumCost(vector<int>& nums) {
        int mx = INT_MAX, mlx = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < mx) {
                swap(mx, mlx);
                mx = nums[i];
            } else if (nums[i] < mlx) {
                mlx = nums[i];
            }
        }
        return nums[0] + mx + mlx;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [10,3,1,1]\n
// @lcpr case=end

 */

