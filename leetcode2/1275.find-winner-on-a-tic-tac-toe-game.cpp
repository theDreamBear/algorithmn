/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 * @lcpr version=30204
 *
 * [1275] 找出井字棋的获胜者
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
    string tictactoe1(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        auto getChar = [&, i = 0] mutable{
            if (i++ % 2 == 0) return 'X';
            else {
                return 'O';
            }
        };
        auto isWin = [&](int x, int y) {
            // 行
            int ct = 0;
            char ch = board[x][y];
            for (int j = 0; j < 3; j++) {
                if (board[x][j] == ch) ct++;
            }
            if (ct == 3) return true;

            // 列
            ct = 0;
            for (int i = 0; i < 3; i++) {
                if (board[i][y] == ch) ct++;
            }
            if (ct == 3) return true;
            //对角线
            if (x != y and x + y != 2) return false;
            if (x == y and board[0][0] == board[1][1] and board[1][1] == board[2][2]) {
                return true;
            }
            if (x + y == 2 and board[2][0] == board[1][1] and board[1][1] == board[0][2]) return true;
            return false;
        };
        for (auto& vec: moves) {
            int x = vec[0], y = vec[1];
            char ch = getChar();
            board[x][y] = ch;
            if (isWin(x, y)) {
                return ch == 'X'? "A" : "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }

    string tictactoe(vector<vector<int>>& moves) {
        int m1 = 0, m2 = 0;
        int i = 0;
        for (auto& vec: moves) {
            int x = vec[0], y = vec[1];
            if (i++ % 2 == 0) {
                m1 |= (1 << ((x * 3) + y));
            } else {
                m2 |= (1 << ((x * 3) + y));
            }
        }
        // 换行 
        // 0-2 1 + 2 + 4 = 7
        // 3-5 8 + 16 + 32 = 56
        // 6-8 64 + 128 + 256 = 448

        // 列 0 3 6 1 + 8 + 64 =  73
        //   1 4 7  128 + 16 + 2 = 146
        //   2  5 8  256 + 32 + 4 = 292

        // 对角线0 4 8 1 + 16 + 256 = 273
        // 对角线2 4 6  4 + 16 + 64 = 84
        vector<int> ac{7, 56, 448, 73, 146, 292, 273, 84};
        auto isWin = [&](int m) {
            for (auto v: ac) {
                if ((v & m) == v) return true;
            }
            return false;
        };
        if (isWin(m1)) {
            return "A";
        }
        if (isWin(m2)) {
            return "B";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[2,0],[1,1],[2,1],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]\n
// @lcpr case=end

 */

