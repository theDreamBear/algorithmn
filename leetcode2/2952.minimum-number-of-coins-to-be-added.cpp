/*
 * @lc app=leetcode.cn id=2952 lang=cpp
 * @lcpr version=30204
 *
 * [2952] 需要添加的硬币的最小数量
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
    // 通过了, 好像不是最优解法
    int minimumAddedCoins1(vector<int>& coins, int target) {
        // o1背包一次
        bitset<100001> bs;
        for (auto v: coins) {
            bs |= bs << v;
            bs.set(v);
        }
        int ans = 0;
        for (int i = 1; i <= target; i++) {
            if (bs.test(i)) continue;
            bs |= bs << i;
            bs.set(i);
            ans++;
        }
        return ans;
    }

    int minimumAddedCoins(vector<int>& coins, int target) {
        // 01背包复杂度高了, 怎么办
        ranges::sort(coins);
        int n = coins.size();
        int ans = 0;
        // [1, preMax] 是已经求得的区间
        for (int i = 0, j = 0; i < target; ) {
            // preMax + v ok
            // diff 是v
            // 需要保证preMax >= v
            if (j < n and i + 1 >= coins[j]) {
                i += coins[j++];
            } else {
                ans++;
                i += (i + 1);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,10]\n19\n
// @lcpr case=end

// @lcpr case=start
// [1,4,10,5,7,19]\n19\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n20\n
// @lcpr case=end

 */

