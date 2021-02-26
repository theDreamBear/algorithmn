/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
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
    bool isToeplitzMatrix1(vector<vector<int>>& matrix) {
        int col = matrix[0].size() - 2;
        int row  = 0;
        while (row < matrix.size() - 1 && col < matrix[0].size() - 1) {
            int pre = matrix[row][col];
            int rn = row + 1;
            int cn = col + 1;
            while (rn < matrix.size() && cn < matrix[0].size()) {
                if (matrix[rn][cn] == pre) {
                    ++rn;
                    ++cn;
                } else {
                    return false;
                }
            }
            if (col > 0) {
                --col;
            } else {
                ++row;
            }
        }
        return true;
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

