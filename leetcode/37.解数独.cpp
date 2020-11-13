/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
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

    void solveSudokuHelper(vector<vector<char>> temp, vector<vector<vector<char>>> & ans, int x, int y) {

        for (int i = x; i < temp.size(); ++i) {
            for (int j = y; j < temp[i].size(); ++j) {
                for (char c = '1'; c <= '9'; ++c) {
                    if (temp[i][j] == '.') {
                        temp[i][j] = c;
                        solveSudokuHelper(temp, ans, i + 1, y);
                        temp[i][j] = '.';
                    }
                }
            }
        }
    }


    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; ++k) {
                        board[i][j] = k;

                    }
                }
            }
        }
    }
};
// @lc code=end

