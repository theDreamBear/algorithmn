/*
 * @lc app=leetcode.cn id=3290 lang=cpp
 * @lcpr version=30204
 *
 * [3290] 最高乘法得分
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
    long long maxScore1(vector<int>& a, vector<int>& b) {
        auto handler = [&](int i, int h) -> pair<bool, long long> {
            if (i < 0) {
                return {true, h == 0 ? 0 : LLONG_MIN / 2};
            }
            return {false, 0};
        };
        int n = b.size();
        long long dp[n][5];
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[i][h];
        };
        for (int i = 0; i < n; i++) {
            dp[i][0] = get_v(i - 1, 0);
            dp[i][1] = max(get_v(i - 1, 1), get_v(i - 1, 0) + (long long)a[0] * b[i]);
            dp[i][2] = max(get_v(i - 1, 2), get_v(i - 1, 1) + (long long)a[1] * b[i]);
            dp[i][3] = max(get_v(i - 1, 3), get_v(i - 1, 2) + (long long)a[2] * b[i]);
            dp[i][4] = max(get_v(i - 1, 4), get_v(i - 1, 3) + (long long)a[3] * b[i]);
        }
        return dp[n - 1][4];
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        auto handler = [&](int i, int h) -> pair<bool, long long> {
            if (h == -1) return {true, 0};
            if (i < 0) return {true, LLONG_MIN / 2};
            return {false, 0};
        };
        int n = b.size();
        int ft = 0, st = 1;
        long long dp[2][4];
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[ft][h];
        };
        for (int i = 0; i < n; i++) {
            dp[st][0] = max(get_v(i - 1, 0), get_v(i - 1, -1) + (long long)a[0] * b[i]);
            dp[st][1] = max(get_v(i - 1, 1), get_v(i - 1, 0) + (long long)a[1] * b[i]);
            dp[st][2] = max(get_v(i - 1, 2), get_v(i - 1, 1) + (long long)a[2] * b[i]);
            dp[st][3] = max(get_v(i - 1, 3), get_v(i - 1, 2) + (long long)a[3] * b[i]);
            swap(ft, st);
        }
        return dp[ft][3];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,5,6]\n[2,-6,4,-5,-3,2,-7]\n
// @lcpr case=end

// @lcpr case=start
// [-1,4,5,-2]\n[-5,-1,-3,-2,-4]\n
// @lcpr case=end

 */
