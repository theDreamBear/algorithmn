/*
 * @lc app=leetcode.cn id=LCR 013 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 013] 二维区域和检索 - 矩阵不可变
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class NumMatrix {
 private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = matrix;
        for (int i = 0; i < prefix.size(); i++) {
            for (int j = 1; j < prefix[i].size(); j++) {
                prefix[i][j] += prefix[i][j - 1];
            }
        }
        for (int j = 0; j < prefix[0].size(); j++) {
            for (int i = 1; i < prefix.size(); i++) {
                prefix[i][j] += prefix[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];
        int top = 0, left = 0, extra = 0;
        if (row1 > 0) {
            top = prefix[row1 - 1][col2];
        }
        if (col1 > 0) {
            left = prefix[row2][col1 - 1];
        }
        if (row1 > 0 and col1 > 0) {
            extra = prefix[row1 - 1][col1 - 1];
        }
        return total - top - left + extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumMatrix","sumRegion","sumRegion","sumRegion"][[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]\n
// @lcpr case=end

 */

