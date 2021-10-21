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
#include <climits>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int minFallingPathSumHelper(const vector<vector<int>>& matrix, vector<vector<int>>& ans, int i, int j) {
        if (i >= matrix.size() || j >= matrix[i].size()) {
            return INT_MAX;
        }
        // 返回
        if (ans[i][j] != INT_MIN) {
            return ans[i][j];
        }
        if (i + 1 > matrix.size()) {
            return INT_MAX;
        }
        // 最后一行
        if (i + 1 == matrix.size()) {
            return ans[i][j] = matrix[i][j];
        }
        int v = INT_MAX;
        int mid = minFallingPathSumHelper(matrix, ans, i + 1, j);
        v = min(v, mid);

        if (j >= 1) {
            // 下左
            int left = minFallingPathSumHelper(matrix, ans, i + 1, j - 1);
            v = min(v, left);
        }
        if (j + 1 <  matrix[i].size()) {
            int right = minFallingPathSumHelper(matrix, ans, i + 1, j + 1);
            v = min(v, right);
        }
        return ans[i][j] = matrix[i][j] + v;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), INT_MIN));
        int res = INT_MAX;
        for (int i = 0; i < matrix[0].size(); i++) {
            int v = minFallingPathSumHelper(matrix, ans, 0, i);
            res = min(res, v);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> ma = {{2, 1, 3}, {6, 5, 4}};
    cout << Solution{}.minFallingPathSum(ma);
}