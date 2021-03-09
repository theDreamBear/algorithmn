/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 防止循环移动先取模
        k = k % (m * n);
        int t = k;
        stack<int> st;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (t > 0) {
                    // 得到最后的k个元素
                    st.push(grid[i][j]);
                    --t;
                } else {
                    // 移动到新位置，这时候最后的k个位置会被覆盖
                    int v = i * n + j + k;
                    int nx = v / n;
                    int ny = v % n;
                    grid[nx][ny] = grid[i][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!st.empty()) {
                    // 设置最后K个元素的新位置
                    grid[i][j] = st.top();
                    st.pop();
                } else {
                    break;
                }
            }
        }
        return grid;
    }
};
// @lc code=end

