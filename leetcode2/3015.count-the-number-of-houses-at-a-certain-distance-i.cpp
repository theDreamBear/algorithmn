// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3015 lang=cpp
 * @lcpr version=30204
 *
 * [3015] 按距离统计房屋对数目 I
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
    vector<int> countOfPairs(int n, int x, int y) {
        x--;
        y--;
        // floyd
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) dp[i][j] = INT_MAX / 2;
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
            if (i + 1 < n) {
                dp[i][i + 1] = 1;
                dp[i + 1][i] = 1;
            }
        }
        if (x != y) {
            dp[x][y] = 1;
            dp[y][x] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != INT_MAX / 2 and dp[i][j]) {
                    ans[dp[i][j] - 1]++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=s
// paramTypes= ["number","number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 3\n1\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n1\n
// @lcpr case=end

 */

