/*
 * @lc app=leetcode.cn id=1575 lang=cpp
 * @lcpr version=30204
 *
 * [1575] 统计所有可行路径
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
int dp[200][210];
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&& dfs, int i, int c) {
            auto& ans = dp[i][c];
            if (ans != -1) return ans;
            ans = 0;
            if (i == finish) ans++;
            if (c == 0) return ans;
            // 继续操作
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int need = abs(locations[i] - locations[j]);
                if (c >= need) {
                    ans = (ans + dfs(dfs, j, c - need)) % mod;
                }
            }
            return ans;
        };
        return dfs(dfs, start, fuel);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,8,4]\n1\n3\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,3,1]\n1\n0\n6\n
// @lcpr case=end

// @lcpr case=start
// [5,2,1]\n0\n2\n3\n
// @lcpr case=end

 */

