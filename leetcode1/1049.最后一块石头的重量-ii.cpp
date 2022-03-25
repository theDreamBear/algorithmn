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
class Solution {
 public:
    int lastStoneWeightII(vector<int> &stones) {
        if (stones.size() == 0) {
            return 0;
        }
        // 找两个集团, 这两个集团尽可能的接近 总体重的一半
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int half = sum / 2;
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
    }
};
// @lc code=end

