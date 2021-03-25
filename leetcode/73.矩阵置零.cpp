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

    void setZeroes1(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0 && !visited[i][j]) {
                    dfs(i, j, matrix, visited);
                }
            }
        }
    }

    /*
        先标记后处理
    */
    void setZeroes2(vector<vector<int>>& matrix) {
        // 标记需要处理的行和列
        vector<bool> visited(matrix.size() + matrix[0].size());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    visited[i]= true;
                    visited[j + matrix.size()] = true;
                }
            }
        }
        // 处理行
        for (int i = 0; i < matrix.size(); ++i) {
            if (visited[i]) {
                 for (int k = 0; k < matrix[0].size(); ++k) {
                     matrix[i][k] = 0;
                 }
            }
        }

        // 处理列
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (visited[j + matrix.size()]) {
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

    }

    void setZeroes2_plus(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rows(m), cols(n);
        // 标记
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = cols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    /*
        使用 matrix 第一列是否有 0
    */
    void setZeroes(vector<vector<int>>& matrix) {
        bool cz = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                cz = true;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][0] == 0) {
                matrix[0][i] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (cz) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end

