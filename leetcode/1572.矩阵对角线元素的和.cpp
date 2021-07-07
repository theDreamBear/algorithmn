/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
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
    bool valid(vector<vector<int>>& mat, int x, int y) {
        return x >= 0 && x < mat.size() && y >= 0 && y < mat[x].size();
    }

    int diagonalSumHelper(vector<vector<int>>& mat, int x, int y, int sx, int sy) {
        int res = 0;
        while (valid(mat, x, y)) {
            res += mat[x][y];
            mat[x][y] = 0;
            x += sx;
            y += sy;
        }
        return res;
    }

    int diagonalSum(vector<vector<int>>& mat) {
        return diagonalSumHelper(mat, 0, 0, 1, 1) + diagonalSumHelper(mat, mat.size() - 1, 0, -1, 1);
    }
};
// @lc code=end

