/*
 * @lc app=leetcode.cn id=LCR 103 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 103] 零钱兑换
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
    int coinChange1(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> memo(amount + 1, 0);
        sort(coins.begin(), coins.end());

        function<int(int)> dfs = [&](int left) {
            if (left < 0) {
                return -1;
            }
            if (left == 0) {
                return 0;
            }
            if (memo[left] != 0) {
                return memo[left];
            }
            int ans = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if (left < coins[i]) {
                    break;
                }
                int res = dfs(left - coins[i]);
                if (res >= 0) {
                    if (ans > res + 1) {
                        ans = res + 1;
                    }
                }
            }
            return ans == INT_MAX ? memo[left] = -1 : memo[left] = ans;
        };
        dfs(amount);
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto v : coins) {
                if (i >= v and memo[i - v] != INT_MAX) {
                    memo[i] = min(memo[i], memo[i - v] + 1);
                }
            }
        }
        return memo[amount] == INT_MAX ? -1 : memo[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1]\n2\n
// @lcpr case=end

 */

