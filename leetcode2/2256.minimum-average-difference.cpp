// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2256 lang=cpp
 * @lcpr version=30204
 *
 * [2256] 最小平均差
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
    int minimumAverageDifference(vector<int>& nums) {
        // fold
        long long sufSum = accumulate(nums.begin(), nums.end(), 0ll);
        long long preSum = 0;
        long long res = INT_MAX, idx = 0;
        int n = nums.size();
        for (int pi = 0; pi + 1 < n; pi++) {
            int v = nums[pi];
            preSum += v;
            sufSum -= v;
            int x = preSum / (pi + 1);
            int y = sufSum / (n - pi - 1);
            if (abs(x - y) < res) {
                res = abs(x - y);
                idx = pi;
            }
        }
        if ((preSum + nums[n - 1]) / n < res) {
            idx = n - 1;
        }
        return idx;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimumAverageDifference
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,5,3,9,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

