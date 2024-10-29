/*
 * @lc app=leetcode.cn id=3259 lang=cpp
 * @lcpr version=30204
 *
 * [3259] 超级饮料的最大强化能量
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
    long long maxEnergyBoost1(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        auto handler = [&](int i, int h) -> pair<bool, long long> {
            if (i < 0) {
                return {true, h == 0 ? 0 : LLONG_MIN / 2};
            }
            return {false, 0};
        };
        int n = energyDrinkA.size();
        long long dp[n][3];
        //fill_array(&dp[0][0], INT_MIN / 2, n, 2);
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[i][h];
        };
        for (int i = 0; i < n; i++) {
            dp[i][0] = max(get_v(i - 1, 1), get_v(i - 1, 2));
            dp[i][1] = max(get_v(i - 1, 0), get_v(i - 1, 1)) + energyDrinkA[i];
            dp[i][2] = max(get_v(i - 1, 2), get_v(i - 1, 0)) + energyDrinkB[i];
        }
        return max({dp[n - 1][1], dp[n - 1][2]});
    }


    // qququaaugccaugkkcaugqkcauugkcaaukccakkck
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        auto handler = [&](int i, int h) -> pair<bool, long long> {
            if (i < 0) {
                return {true, 0};
            }
            return {false, 0};
        };
        int n = energyDrinkA.size();
        long long dp[2][3];
        int ft = 0, st = 1;
        //fill_array(&dp[0][0], INT_MIN / 2, n, 2);
        auto get_v = [&](int i, int h) {
            if (auto res = handler(i, h); res.first) {
                return res.second;
            }
            return dp[ft][h];
        };
        for (int i = 0; i < n; i++) {
            dp[st][0] = max(get_v(i - 1, 1), get_v(i - 1, 2));
            dp[st][1] = max(get_v(i - 1, 0), get_v(i - 1, 1)) + energyDrinkA[i];
            dp[st][2] = max(get_v(i - 1, 2), get_v(i - 1, 0)) + energyDrinkB[i];
            swap(ft, st);
        }
        return max({dp[ft][1], dp[ft][2]});
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,1]\n[3,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,1]\n[1,1,3]\n
// @lcpr case=end

 */
