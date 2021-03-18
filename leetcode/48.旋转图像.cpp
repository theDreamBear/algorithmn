/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
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
    /*
        空间换时间
    */
    void rotate1(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[j][i] = temp[n - i - 1][j];
            }
        }
        return;
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    /*
        一圈一圈旋转
    */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x = n / 2 - 1;
        int y = n / 2 - 1;
        int times = (n % 2 == 0) ? 1 : 2;
        while (x >= 0 && y >= 0) {
            int t = times;
            while (t-- > 0) {
                int temp = matrix[x][y];
                int nx = x;
                int ny = y;
                for (int k = 0; k < 4; ++k) {
                    while (nx <= n - x - 1 && ny <= n - y - 1) {
                        int x0 = nx + dx[k];
                        int y0 = ny + dy[k];
                        if (k == 0 && x0 > (n - x - 1)) {
                            break;
                        }
                        if (k == 1 && y0 > (n - y - 1)) {
                            break;
                        }
                        if (k == 2 && x0 < x) {
                            break;
                        }
                        if (k == 3 && y0 < y) {
                            break;
                        }
                        matrix[nx][ny] = matrix[x0][y0];
                        nx = x0;
                        ny = y0;
                    }
                }
                matrix[x][y + 1] = temp;
            }
            times += 2;
            x = x - 1;
            y = y - 1;
        }
        return;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> data{
        {1, 2 ,3},
        {4, 5, 6},
        {7, 8, 9},
    };
    Solution{}.rotate(data);
}