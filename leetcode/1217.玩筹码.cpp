/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
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
class Solution {
public:
    int minCostToMoveChips1(vector<int>& position) {
        unordered_map<int, int> hash;
        for (auto v : position) {
            ++hash[v];
        }
        int ans = INT_MAX;
        for (auto kv : hash) {
            int cost = 0;
            for (auto kv2 : hash) {
                if ((kv.first - kv2.first) % 2 != 0) {
                    cost += kv2.second;
                }
            }
            if (cost < ans) {
                ans = cost;
            }
        }
        return ans;
    }

    /*
        最终位置要么为奇数位置要么为偶数位置, 只需要统计 奇数到偶数代价 偶数到奇数代价,取最小值
    */
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (auto v : position) {
            if (v % 2 == 0) {
                even += 1;
            } else {
                odd += 1;
            }
        }
        return min(odd, even);
    }
};
// @lc code=end

