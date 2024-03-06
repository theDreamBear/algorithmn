/*
 * @lc app=leetcode.cn id=LCR 188 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 188] 买卖芯片的最佳时机
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
    int bestTiming(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        adjacent_difference(prices.begin(), prices.end(), prices.begin());
        prices[0] = 0;
        int ans = 0;
        int tmp = 0;
        for (auto v : prices) {
            if (tmp <= 0) {
                tmp = v;
            } else {
                tmp += v;
            }
            ans = max(ans, tmp);
        }
        ans = max(ans, tmp);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3, 6, 2, 9, 8, 5]\n
// @lcpr case=end

// @lcpr case=start
// [8, 12, 15, 7, 3, 10]\n
// @lcpr case=end

 */

