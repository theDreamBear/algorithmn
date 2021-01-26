/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */
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
    int smoothAvg(const vector<vector<int>>& M, int x, int y) {
        int sum = 0;
        int ct = 0;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                int xx = x + i;
                int yy = y + j;
                if (xx < 0 || xx >= M.size() || y < 0 || yy >= M[xx].size()) {
                    continue;
                }
                ++ct;
                sum += M[xx][yy];
            }
        }
        return sum / ct;
    }

    vector<vector<int>> imageSmoother1(vector<vector<int>>& M) {
        vector<vector<int>> ans = M;
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M[i].size(); ++j) {
                ans[i][j] = smoothAvg(M, i, j);
            }
        }
        return ans;
    }

    void preprocessing(const vector<vector<int>>& M, vector<vector<int>>& sum) {
        if (M.size() == 0) {
            return;
        }
        int s = 0;
        for (int i = 0; i < M.size(); ++i) {
            s += M[i][0];
            sum[i][0] = s;
        }
        s = 0;
        for (int i = 0; i < M[0].size(); ++i) {
            s += M[0][i];
            sum[0][i] = s;
        }

        for (int i = 1; i < M.size(); ++i) {
            for (int j = 1; j < M[i].size(); ++j) {
                sum[i][j] =
                    sum[i - 1][j] + sum[i][j - 1] + M[i][j] - sum[i - 1][j - 1];
            }
        }
    }

    /*
        使用前缀和加速
    */
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans = M;
        vector<vector<int>> sum(M.size(), vector<int>(M[0].size()));
        preprocessing(M, sum);
        int rows = M.size();
        int cols = M[0].size();
        // 边界用老方法处理
        for (int i = 0; i < rows; ++i) {
            ans[i][0] = smoothAvg(M, i, 0);
            if (cols - 1 >= 0) {
                ans[i][cols - 1] = smoothAvg(M, i, cols - 1);
            }
        }
        for (int i = 0; i < cols; ++i) {
            ans[0][i] = smoothAvg(M, 0, i);
            if (rows - 1 >= 0) {
                ans[rows - 1][i] = smoothAvg(M, rows - 1, i);
            }
        }
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                int left = (j - 2 >= 0) ? sum[i + 1][j - 2]: 0;
                int up = (i - 2 >= 0) ? sum[i - 2][j + 1] : 0;
                int lu = (i - 2 >= 0 && j - 2 >= 0) ? sum[i - 2][j - 2]: 0;
                ans[i][j] = (sum[i + 1][j + 1] - left - up + lu) / 9;
            }
        }
        return ans;
    }
};
// @lc code=end
