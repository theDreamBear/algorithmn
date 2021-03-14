/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
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

    int findMaxSquare(vector<vector<char>>& matrix, int i, int j) {
        int maxAra = 1;
        int t = 1;
        while (i + t >= 0 && i + t < matrix.size() && j + t >= 0 && j + t < matrix[i + t].size()) {
            int nx = i + t;
            int ny = j + t;
            for (int x = i; x <= nx; ++x) {
                if (matrix[x][ny] == '0') {
                    return maxAra;
                }
            }
            for (int y = j; y < ny; ++y) {
                if (matrix[nx][y] == '0') {
                    return maxAra;
                }
            }
            maxAra = (t + 1) * (t + 1);
            ++t;
        }
        return maxAra;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    int area = findMaxSquare(matrix, i, j);
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end

int main() {
    vector<vector<char>> data={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << Solution{}.maximalSquare(data);
}
