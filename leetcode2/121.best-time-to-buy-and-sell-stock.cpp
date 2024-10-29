/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30204
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        vector<int> sub(n - 1);
        for (int i = 1; i < n; i++) {
            sub[i - 1] = prices[i] - prices[i - 1];
        }
        int ans = 0;
        int cur = 0;
        for (auto v: sub) {
            cur += v;
            // 选不选当前商品
            cur = max(cur, v);
            ans = max(ans, cur);
        }
        return ans;
    }

    // 分组循环求每个波峰波谷
    int maxProfit(vector<int>& prices) {
        int mm = prices[0];
        int ans = 0;
        for (auto v : prices) {
            ans = max(ans, v - mm);
            mm = min(mm, v);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

