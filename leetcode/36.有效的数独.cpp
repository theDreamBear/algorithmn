/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
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
    bool rowValid(int row, int col, const vector<vector<char>>& board) {
        int index = 0;
        while (index < board[row].size()) {
            if (index != col && board[row][col] == board[row][index]) {
                return false;
            }
            ++index;
        }
        return true;
    }

    bool colValid(int row, int col, const vector<vector<char>>& board) {
        int index = 0;
        while (index < board.size()) {
            if (index != row && board[row][col] == board[index][col]) {
                return false;
            }
            ++index;
        }
        return true;
    }

    bool rectangleValid(int row, int col, const vector<vector<char>>& board) {
        int px = row / 3 * 3;
        int py = col / 3 * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int x = px + i;
                int y = py + j;
                if (x == row && y == col) {
                    continue;
                }
                if (board[row][col] == board[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] >= '0' && board[i][j] <= '9') {
                    if (!rowValid(i, j, board) || !colValid(i, j, board) ||
                        !rectangleValid(i, j, board)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
