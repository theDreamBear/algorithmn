/*
 * @lc app=leetcode.cn id=1883 lang=cpp
 * @lcpr version=30122
 *
 * [1883] 准时抵达会议现场的最小跳过休息次数
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
    // 万恶的浮点精度
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        // y
        int total = accumulate(dist.begin(), dist.end(), 0);
        double min_cost = total * 1.0 / speed;
        if (min_cost > hoursBefore) {
            return -1;
        }
        int n = dist.size();
        double deadTime = hoursBefore - dist.back() * 1.0 / speed;
        vector<vector<double>> dp(n, vector<double>(n, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                double small = dist[i - 1] * 1.0 / speed;
                int big = ceil(small);
                if (dp[i - 1][j] != INT_MAX) {
                    dp[i][j] = ceil(dp[i - 1][j] + dist[i - 1] * 1.0 / speed - 1e-7);
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + small);
                }
            }
        }
        return lower_bound(dp.back().begin(), dp.back().end(), deadTime, [](double left, double right) {
            return left > right + 1e-7;
        }) - dp.back().begin();
        // for (int i = 0; i < n; i++) {
        //     if (dp[n - 1][i] <= deadTime + 1e-7) {
        //         return i;
        //     }
        // }
        // return -1;
    }


    int minSkips2(vector<int>& dist, int speed, int hoursBefore) {
        int total = accumulate(dist.begin(), dist.end(), 0);
        if (total > (long long)hoursBefore * speed) {
            return -1;
        }
        int n = dist.size();
        /*
            dp[i][j] 从第i个出发前跑的最短距离
            dp[0][0] = 0;
            dp[i][j]  = min(dp[i - 1][j] + small or big, dp[i - 1][j - 1] + small);

        */
        int deadDis = (long long)hoursBefore * speed - dist.back();
        vector<vector<unsigned int>> dp(n, vector<unsigned int>(n, UINT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int small = dist[i - 1];
                int big = ceil(dist[i - 1] * 1.0 / speed) * speed;
                if (dp[i - 1][j] != UINT_MAX) {
                    // 这个是错的
                    //dp[i][j] = dp[i - 1][j] + (((small + dp[i - 1][j]) % speed == 0) ? small : big);
                    dp[i][j] = ceil((dp[i - 1][j] + small) * 1.0 / speed) * speed;
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + small);
                }
            }
        }
        return lower_bound(dp.back().begin(), dp.back().end(), deadDis, greater<>{}) - dp.back().begin();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,3,5,5]\n2\n10\n
// @lcpr case=end

// @lcpr case=start
// [7,3,5,5]\n1\n10\n
// @lcpr case=end

 */

