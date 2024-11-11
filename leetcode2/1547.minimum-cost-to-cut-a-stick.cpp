// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 * @lcpr version=30204
 *
 * [1547] 切棍子的最小成本
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
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minCost1(int n, vector<int>& cuts) {
        ranges::sort(cuts);
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int dp[200][200];
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto&& dfs, int low, int high)->int {
            // 空块
            if (low >= high) return 0;
            // 已经是单块了, 不需要继续切割
            if (low + 1 == high) {
                return 0;
            }
            if (dp[low][high] != -1) {
                return dp[low][high];
            }
            int res = INT_MAX;
            for (int i = low + 1; i < high; i++) {
                res = min(res, dfs(dfs, low, i) + dfs(dfs, i, high) + cuts[high] - cuts[low]);
            }
            return dp[low][high] = res;
        };
        return dfs(dfs, 0, cuts.size() - 1);
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        ranges::sort(cuts);
        int dp[200][200];
        memset(dp, 0, sizeof dp);
        // 单块为0, 想通为0;
        for (int step = 2; step < cuts.size(); step++) {
            for (int i = 0; i + step < cuts.size(); i++) {
                dp[i][i + step] = INT_MAX;
                for (int k = 1; k < step; k++) {
                    dp[i][i + step] = min(dp[i][i + step], dp[i][i + k] + dp[i + k][i + step] + cuts[i + step] - cuts[i]);
                }
            }
        }
        return dp[0][cuts.size() - 1];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minCost
// paramTypes= ["number","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 7\n[1,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// 9\n[5,6,1,4,2]\n
// @lcpr case=end

 */

