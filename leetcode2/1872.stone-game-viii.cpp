/*
 * @lc app=leetcode.cn id=1872 lang=cpp
 * @lcpr version=30204
 *
 * [1872] 石子游戏 VIII
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
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        int sum[n + 1];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + stones[i];
        }
        int sufMax = sum[n];
        int ans = sufMax;
        for (int i = n - 2; i > 0; i--) {
            sufMax = max(sufMax, sum[i + 1] - sufMax);
            ans = max(ans, sufMax);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,2,-3,4,-5]\n
// @lcpr case=end

// @lcpr case=start
// [7,-6,5,10,5,-2,-6]\n
// @lcpr case=end

// @lcpr case=start
// [-10,-12]\n
// @lcpr case=end

 */

