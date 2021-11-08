/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
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
    // 超时
    int totalHammingDistance1(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                unsigned v = nums[i] ^ nums[j];
                ans += __builtin_popcount(v);
            }
        }
        return ans;
    }

    // 怎么打破 n^2 的瓶颈, 只能想办法批量操作
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 31; i >= 0; i--) {
            int ct = 0;
            for (auto v : nums) {
                if ((v >> i) & 0x1) {
                    ++ct;
                }
            }
            ans += ct * (n - ct);
        }
        return ans;
    }
};
// @lc code=end

