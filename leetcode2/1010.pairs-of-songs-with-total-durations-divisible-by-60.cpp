/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 * @lcpr version=30204
 *
 * [1010] 总持续时间可被 60 整除的歌曲
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
    int numPairsDivisibleBy60(vector<int>& time) {
        int dp[60]{};
        int ans = 0;
        for (auto v: time) {
            ans += dp[(60 - (v % 60)) % 60];
            dp[v % 60]++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [30,20,150,100,40]\n
// @lcpr case=end

// @lcpr case=start
// [60,60,60]\n
// @lcpr case=end

 */

