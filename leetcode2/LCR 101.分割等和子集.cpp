/*
 * @lc app=leetcode.cn id=LCR 101 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 101] 分割等和子集
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // bitset加速
    bool canPartition_bitset(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total & 0x1) {
            return false;
        }
        int left = total >> 1;
        // dp
        bitset<100001> bs;
        bs.set(0, 1);
        for (int v : nums) {
            bs = bs | bs << v;
        }
        return bs.test(left);
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total & 0x1) {
            return false;
        }
        int left = total >> 1;
        // dp
        vector<int> dp(left + 1);
        dp[0] = 1;
        for (int v : nums) {
            for (int j = left; j >= v; j--) {
                if (dp[j - v]) {
                    dp[j] = 1;
                }
            }
        }
        return dp[left];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */

