/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 *
 * [1275] 找出井字棋的获胜者
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
constexpr static int row = 3;
class Solution {
 public:
    bool isWinHelper(const vector<vector<char>> &grid, char goal, int x, int y, int dx, int dy) {
        int t = 0;
        while (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size()) {
            char c = grid[x][y];
            if (c != goal) {
                return false;
            }
            ++t;
            x += dx;
            y += dy;
        }
        return t == grid.size();
    }

    bool isWin(const vector<vector<char>> &grid, int x, int y) {
        char goal = grid[x][y];
        // 行
        if (isWinHelper(grid, goal, x, 0, 0, 1)) {
            return true;
        }
        // 列
        if (isWinHelper(grid, goal, 0, y, 1, 0)) {
            return true;
        }

        // 斜对角线
        if (x == y && isWinHelper(grid, goal, 0, 0, 1, 1)) {
            return true;
        }
        // 反斜对角线
        if (x + y == (row - 1) && isWinHelper(grid, goal, row - 1, 0, -1, 1)) {
            return true;
        }

        return false;
    }

    string tictactoe(vector<vector<int>> &moves) {
        vector<vector<char>> grid(row, vector<char>(row, ' '));
        for (int i = 0; i < moves.size(); i++) {
            auto x = moves[i][0];
            auto y = moves[i][1];
            char c = ' ';
            if (i % 2 == 0) {
                c = 'X';
            } else {
                c = 'O';
            }
            grid[x][y] = c;
            if (isWin(grid, x, y)) {
                if (c == 'X') {
                    return "A";
                } else {
                    return "B";
                }
            }
        }
        if (moves.size() < row * row) {
            return "Pending";
        }
        return "Draw";
    }
};
// @lc code=end

