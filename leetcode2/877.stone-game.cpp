/*
 * @lc app=leetcode.cn id=877 lang=cpp
 * @lcpr version=30204
 *
 * [877] 石子游戏
 * 
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
    bool stoneGame1(vector<int>& piles) {
        int sum[1000]{};
        for (int i = 0; i < piles.size(); i++) {
            sum[i + 1] = sum[i] + piles[i];
        }
        int dp[1000][1000]{};
        auto dfs = [&](auto&& dfs, int l, int r) {
            if (l == r) {
                return piles[l];
            }
            if (dp[l][r]) return dp[l][r];
            return dp[l][r] = max(piles[l] + sum[r + 1] - sum[l] - dfs(dfs, l + 1, r), piles[r] + sum[r + 1] - sum[l] - dfs(dfs, l, r - 1));
        };
        return dfs(dfs, 0, piles.size() - 1) > sum[piles.size()] / 2;
    }

    bool stoneGame2(vector<int>& piles) {
        int sum[1000]{};
        for (int i = 0; i < piles.size(); i++) {
            sum[i + 1] = sum[i] + piles[i];
        }
        int dp[1000][1000]{};
        int n = piles.size();
        auto query = [&](int l, int r) {
            return sum[r + 1] - sum[l];
        };
        for (int step = 1; step < n; step++) {
            for (int i = 0; i + step < n; i++) {
                int j = i + step;
                dp[i][j] = max(piles[i] + query(i+1, j) - dp[i+1][j], piles[j] + query(i, j-1)-dp[i][j-1]);
            }
        }
        return dp[0][n - 1] > query(0, n - 1) / 2;
    }

    bool stoneGame3(vector<int>& piles) {
        int sum[1000]{};
        int dp[1000][1000]{};
        int n = piles.size();
        for (int step = 1; step < n; step++) {
            for (int i = 0; i + step < n; i++) {
                int j = i + step;
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][n - 1] > 0;
    }

    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,7,2,3]\n
// @lcpr case=end

 */

