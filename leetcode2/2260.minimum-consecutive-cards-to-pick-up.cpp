/*
 * @lc app=leetcode.cn id=2260 lang=cpp
 * @lcpr version=30204
 *
 * [2260] 必须拿起的最小连续卡牌数
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
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mv;
        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            if (mv.count(cards[i])) {
                ans = min(ans, i - mv[cards[i]] + 1);
            }
            mv[cards[i]] = i;
        }
        return ans == INT_MAX ? -1 :ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,2,3,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,5,3]\n
// @lcpr case=end

 */

