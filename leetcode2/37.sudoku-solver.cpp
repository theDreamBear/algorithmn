/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30114
 *
 * [37] 解数独
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string adj(vector<vector<char>>& board, int i, int j) {
        string can = "123456789";
        // 行
        for (int k = 0; k < 9; k++) {
            if (board[i][k] != '.') {
                can[board[i][k] - '1'] = '0';
            }
        }
        // 列
        for (int k = 0; k < 9; k++) {
            if (board[k][j] != '.') {
                can[board[k][j] - '1'] = '0';
            }
        }
        // 小正方形
        int pi = i / 3 * 3;
        int pj = j / 3 * 3;;
        for (int px = 0; px < 3; px++) {
            for (int py = 0; py < 3; py++) {
                int nx = pi + px;
                int ny = pj + py;
                if (board[nx][ny] != '.') {
                    can[board[nx][ny] - '1'] = '0';
                }
            }
        }
        string ans;
        for (int k = 0; k < 9; k++) {
            if (can[k] != '0') {
                ans.push_back(k + 1 + '0');
            }
        }
        return ans;
    }

    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    auto can = adj(board, i, j);
                    if (can.empty()) {
                        return false;
                    }
                    for (auto v : can) {
                        board[i][j] = v;
                        if (backtrack(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board, int x, int y) {
        // 处理第x行, 丑陋
        // for (int k = y; k < 9; k++) {
        //     if (board[x][k] == '.') {
        //         auto can = adj(board, x, k);
        //             if (can.empty()) {
        //                 return false;
        //             }
        //             for (auto v : can) {
        //                 board[x][k] = v;
        //                 if (backtrack(board)) {
        //                     return true;
        //                 }
        //                 board[x][k] = '.';
        //             }
        //         return false;
        //     }
        // }
        // for (int i = x + 1; i < 9; i++) {
        //     for (int j = 0; j < 9; j++) {
        //         if (board[i][j] == '.') {
        //             auto can = adj(board, x, j);
        //             if (can.empty()) {
        //                 return false;
        //             }
        //             for (auto v : can) {
        //                 board[i][j] = v;
        //                 if (backtrack(board)) {
        //                     return true;
        //                 }
        //                 board[i][j] = '.';
        //             }
        //         return false;
        //     }
        //     }
        // }

        // 稍微优美
        for (int idx = x * 9 + y; idx < 81; idx++) {
            int i = idx / 9;
            int j = idx % 9;
            if (board[i][j] == '.') {
                auto can = adj(board, x, j);
                if (can.empty()) {
                    return false;
                }
                for (auto v : can) {
                    board[i][j] = v;
                    if (backtrack(board)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        //backtrack(board);
        backtrack(board, 0, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

