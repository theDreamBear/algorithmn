/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30122
 *
 * [152] 乘积最大子数组
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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpma(n), dpmm(n);
        dpma[0] = dpmm[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dpma[i] = max({nums[i], nums[i] * dpma[i - 1], nums[i] * dpmm[i - 1]});
            dpmm[i] = min({nums[i], nums[i] * dpma[i - 1], nums[i] * dpmm[i - 1]});
        }
        return *max_element(dpma.begin(), dpma.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */



