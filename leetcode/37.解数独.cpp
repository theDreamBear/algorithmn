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
    /*
        这个函数不能写错
    */
    vector<int> candidateNums(vector<vector<char>> &board, int row, int col) {
        vector<int> ans;
        vector<int> used(10);
        // 行
        for (int i = 0; i < board[row].size(); ++i) {
            if (board[row][i] == '.') {
                continue;
            }
            ++used[board[row][i] - '0'];
        }
        // 列
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][col] == '.') {
                continue;
            }
            ++used[board[i][col] - '0'];
        }
        // 矩形
        int px = row / 3 * 3;
        int py = col / 3 * 3;
        for (int i = px; i < 3 + px; ++i) {
            for (int j = py; j < 3 + py; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                ++used[board[i][j] - '0'];
            }
        }
        for (int i = 1; i <= 9; ++i) {
            if (!used[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    bool solveSudokuHelper(vector<vector<char>> &board, int x, int y, int &leftSpace) {
        // 出口
        if (leftSpace == 0) {
            return true;
        }
        bool found = false;
        // 找下一个位置
        for (int i = y; i < board[x].size(); ++i) {
            if (board[x][i] == '.') {
                y = i;
                found = true;
                break;
            }
        }
        for (int i = x + 1; i < board.size(); ++i) {
            if (found) {
                break;
            }
            if (!found) {
                for (int j = 0; j < board[i].size(); ++j) {
                    if (board[i][j] == '.') {
                        x = i;
                        y = j;
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found) {
            cout << "error";
            return false;
        }
        // 找后补数字
        auto can = candidateNums(board, x, y);
        // 填错了
        if (can.size() == 0) {
            return false;
        }
        // 尝试候补数字
        for (int i = 0; i < can.size(); ++i) {
            board[x][y] = can[i] + '0';
            --leftSpace;
            if (solveSudokuHelper(board, x, y, leftSpace)) {
                return true;
            }
            board[x][y] = '.';
            ++leftSpace;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board) {
        int leftSpace = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    ++leftSpace;
                }
            }
        }
        solveSudokuHelper(board, 0, 0, leftSpace);
    }
};
// @lc code=end

int main() {
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution{}.solveSudoku(board);

    for (auto &vec : board) {
        for (auto &v : vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
