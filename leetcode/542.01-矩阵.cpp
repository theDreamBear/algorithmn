/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
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
    constexpr static int base = 10e4 + 1;
    constexpr static int dx[4] = {0, -1, 0, 1};
    constexpr static int dy[4] = {-1, 0, 1, 0};

    vector<vector<int>> updateMatrix_bfs(vector<vector<int>> &mat) {
        vector<vector<int>> ans = mat;
        priority_queue<int, vector<int>, greater<>> small;
        int m = mat.size();
        int n = mat[0].size();


        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    int v = i * n + j;
                    small.push(v);
                } else {
                    ans[i][j] = INT_MAX;
                }
            }
        }
        while (!small.empty()) {
            auto node = small.top();
            small.pop();
            int v = node % base;
            int x = v / n;
            int y = v % n;
            int weight = node / base + 1;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || ans[nx][ny] <= weight) {
                    continue;
                }
                ans[nx][ny] = weight;
                small.push(weight * base + (nx * n + ny));
            }
        }
        return ans;
    }

    // dp ,可以再看看题解
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        if (mat.empty()) {
            return {{}};
        }
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                }
            }
        }
        // 左上
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (j > 0) {
                    ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
                }
                if (i > 0) {
                    ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
                }
            }
        }
        // 右下
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j < n - 1) {
                    ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
                }
                if (i < m - 1) {
                    ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

