/*
 * @lc app=leetcode.cn id=2745 lang=cpp
 * @lcpr version=30204
 *
 * [2745] 构造最长的新字符串
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
    int longestString1(int x, int y, int z) {
        auto handler = [&](int i, int j, int k) -> pair<bool, int> {
            if (i < 0 || j < 0 || k < 0) {
                return {true, -2};
            }
            return {false, 0};
        };
        int dp[x + 1][y + 1][z + 1][3];
        //fill_array(&dp[0][0], INT_MIN / 2, n, 2);
        auto get_v = [&](int i, int j, int k, int s) {
            if (auto res = handler(i, j, k); res.first) {
                return res.second;
            }
            return dp[i][j][k][s];
        };
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                for (int k = 0; k <= z; k++) {
                    dp[i][j][k][0] = max(get_v(i - 1, j , k, 1), get_v(i - 1, j, k, 2)) + 2;
                    dp[i][j][k][1] = max({get_v(i, j, k - 1, 2), get_v(i, j, k - 1, 1)}) + 2;
                    dp[i][j][k][2] = get_v(i, j - 1, k, 0) + 2;
                }
            }
        }
        return max({dp[x][y][z][0], dp[x][y][z][1], dp[x][y][z][2]});
    }

    int longestString(int x, int y, int z) {
        return 2 * (min(x, y) * 2 + (x != y) + z);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n2\n
// @lcpr case=end

 */
