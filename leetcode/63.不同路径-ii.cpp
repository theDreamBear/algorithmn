/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 起点为障碍物不用算了
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;
        
        // 第一行初始化
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 0) {
                obstacleGrid[0][i] = obstacleGrid[0][i - 1];
            } else {
                obstacleGrid[0][i] = 0;
            }
        }
        // 第一列 
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                obstacleGrid[i][0] = obstacleGrid[i - 1][0];
            } else {
                obstacleGrid[i][0] = 0;  
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    // 障碍物改成0
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};
// @lc code=end

int main() {
    vector<vector<int>> data{
        {0, 0},
        {1, 1},
        {0, 0},
    };
    cout << Solution{}.uniquePathsWithObstacles(data);
}