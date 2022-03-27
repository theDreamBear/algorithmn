/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int min_one = INT_MAX;
                for (int k = -1; k < 2; k++) {
                    int dj = j + k;
                    if (dj < 0 || dj >= matrix[i].size()) {
                        continue;
                    }
                    min_one = min(min_one, matrix[i - 1][dj]);
                }
                matrix[i][j] += min_one;
            }
        }
        int ans = INT_MAX;
        for (auto v : matrix.back()) {
            ans = min(ans, v);
        }
        return ans;
    }
};
// @lc code=end

