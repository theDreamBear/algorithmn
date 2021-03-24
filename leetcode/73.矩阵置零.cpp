/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
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
    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        for (int k = 0; k < matrix.size(); ++k) {
            if (matrix[k][j] != 0) {
                visited[k][j] = true;
                matrix[k][j] = 0;
            } else if (!visited[i][j]) {
                dfs(k, j, matrix, visited);
            }
        }
        for (int k = 0; k < matrix[i].size(); ++k) {
            if (matrix[i][k] != 0) {
                matrix[i][k] = 0;
                visited[i][k] = true;
            } else if (!visited[i][k]) {
                dfs(i, k, matrix, visited);
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0 && !visited[i][j]) {
                    dfs(i, j, matrix, visited);
                }
            }
        }
    }
};
// @lc code=end

