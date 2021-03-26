/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
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


    int dfs(int i , int j, const vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        int left = dfs(i + 1, j, triangle, dp);
        int right = dfs(i + 1 , j + 1, triangle, dp);
        dp[i][j] = triangle[i][j] + min(left, right);
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), INT_MAX));
        return dfs(0, 0, triangle, dp);
    }
};
// @lc code=end

