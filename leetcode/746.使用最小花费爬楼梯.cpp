/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
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
    /*
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    */
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int pre = 0;
        int prepre = 0;
        for (int i = 2; i < cost.size(); ++i) {
            int temp = min(pre + cost[i - 1], prepre + cost[i - 2]);
            prepre = pre;
            pre = temp;
        }
        return pre;
    }
};
// @lc code=end

