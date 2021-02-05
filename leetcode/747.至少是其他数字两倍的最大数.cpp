/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
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

using namespace std;

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto max_val = max_element(nums.begin(), nums.end());
        for (auto v : nums) {
            if (v != *max_val && 2 * v > *max_val) {
                return -1;
            }
        }
        return max_val - nums.begin();
    }
};
// @lc code=end

