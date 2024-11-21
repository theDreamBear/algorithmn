// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1690 lang=cpp
 * @lcpr version=30204
 *
 * [1690] 石子游戏 VII
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
    int stoneGameVII1(vector<int>& stones) {
        int n = stones.size();
        int sum[n + 100];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + stones[i];
        }
        auto get = [&](int l, int r) {
            return sum[r + 1] - sum[l];
        };
        vector<vector<int>> dp(n + 100, vector<int>(n + 100, INT_MIN));
        auto dfs = [&](auto&& dfs, int l, int r) {
            if (l >= r) return 0;
            if (dp[l][r] != INT_MIN) return dp[l][r];
            int v = get(l, r);
            int res = max(v - stones[l] - dfs(dfs, l + 1, r), v - stones[r] - dfs(dfs, l, r - 1));
            return dp[l][r] = res;
        };
        return dfs(dfs, 0, n - 1);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int sum[n + 100];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + stones[i];
        }
        auto get = [&](int l, int r) {
            return sum[r + 1] - sum[l];
        };
        vector<vector<int>> dp(2, vector<int>(n + 100, 0));
        int ft = 0, st = 1;
        for (int step = 2; step <= n; step++) {
            for (int i = 0; i + step <= n; i++) {
                int j = i + step - 1;
                dp[st][j] = max(-dp[ft][j] + get(i + 1, j), -dp[ft][j - 1] + get(i, j - 1));
            }
            swap(ft, st);
        }
        return dp[ft][n-1];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=stoneGameVII
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [5,3,1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [7,90,5,1,100,10,10,2]\n
// @lcpr case=end

 */

