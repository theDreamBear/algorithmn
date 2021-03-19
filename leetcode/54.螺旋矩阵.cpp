/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
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
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool valide(int k , int x, int y, int m, int n) {
        if (k == 0 && y >= n) {
            return false;
        }
        if (k == 1 && x >= m) {
            return false;
        }
        if (k == 2 && y < 0) {
            return false;
        }
        if (k == 3 && x < 0) {
            return false;
        }
        return true;
    }

    /*
        模拟
    */
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m * n);
        int i = 0;
        int nx = 0;
        int ny = 0;
        ans[i++] = matrix[nx][ny];
        matrix[nx][ny] = INT_MAX;
        while (i < ans.size()) {
            for (int k = 0; k < 4; ++k) {
                while (true) {
                    int x0 = nx + dx[k];
                    int y0 = ny + dy[k];
                    if (!valide(k, x0, y0, m, n) || matrix[x0][y0] == INT_MAX) {
                        break;
                    }
                    nx = x0;
                    ny = y0;
                    ans[i++] = matrix[nx][ny];
                    matrix[nx][ny] = INT_MAX;
                }
            }
        }
        return ans;
    }

    /*
        非常有意思的做法
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m * n);
        int index = 0;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (true) {
            for (int i = left; i <= right; ++i) {
                ans[index++] = matrix[top][i];
            }
            if (++top > bottom) {
                break;
            }
            for (int i = top; i <= bottom; ++i) {
                ans[index++] = matrix[i][right];
            }
            if (--right < left) {
                break;
            }
            for (int i = right; i >= left; --i) {
                ans[index++] = matrix[bottom][i];
            }
            if (--bottom < top) {
                break;
            }
            for (int i = bottom; i >= top; --i) {
                ans[index++] = matrix[i][left];
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

