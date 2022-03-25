/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
//#define one
//#define two
#define three
#define MAX_N 3005

class Solution {
 public:
    int lastStoneWeightII(vector<int> &stones) {
        if (stones.size() == 0) {
            return 0;
        }
        // 找两个集团, 这两个集团尽可能的接近 总体重的一半
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int half = sum / 2;
#ifdef one
        // 0 1 背包
        vector<bool> backpack(sum + 1, false);
        backpack[0] = true;
        for (auto weight : stones) {
            for (int w = sum - weight; w >= 0; w--) {
                if (backpack[w]) {
                    backpack[w + weight] = true;
                }
            }
        }
        int left = 0;
        for (int i = half; i >= 0; i--) {
            if (backpack[i]) {
                left = i;
                break;
            }
        }
        return sum - 2 * left;
#endif
#ifdef two  // 基操
        //  定义: dp[i][j] 前i 个背包为 j 是否可能
        //  初始化 dp[0][0] = true
        //        dp[0][非 0] = false;
        //        dp[非 0][0] = true;
        //  转移公式   dp[i][j] = dp[i - 1][j], dp[i - 1][j - stone[i - 1]]
         vector<vector<bool>> dp(stones.size() + 1, vector<bool>(sum + 1));
         for (int i = 0; i < stones.size() + 1; i++) {
             dp[i][0] = true;
         }
         for (int i = 1 ; i < stones.size() + 1; i++) {
             for (int j = 1; j < dp[i].size(); j++) {
                 dp[i][j] = dp[i - 1][j];
                 if (!dp[i][j] && j >= stones[i - 1]) {
                     dp[i][j] = dp[i - 1][j - stones[i - 1]];
                 }
             }
         }
         int left = INT_MAX;
         int i = stones.size();
         for (int j = half; j >= 0; j--) {
             if (dp[i][j]) {
                 left = j;
                 break;
             }
         }
         return sum - 2 * left;
#endif
#ifdef three
        // 位操作
        bitset<MAX_N> bs;
        bs.set(0);
        for (auto v : stones) {
            bs |= (bs << v);
        }
        int left = INT_MAX;
        for (int j = half; j >= 0; j--) {
            if (bs[j]) {
                left = j;
                break;
            }
        }
        return sum - 2 * left;
#endif
    }
};
// @lc code=end

