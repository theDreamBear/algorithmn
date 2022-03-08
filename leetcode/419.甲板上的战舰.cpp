/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution {
 public:

    int countBattleships(vector<vector<char>>& board) {
        int ship_ct = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'X') {
                    ship_ct++;
                    int z = j;
                    while (z < board[i].size() && board[i][z] == 'X') {
                        board[i][z] = '.';
                        z++;
                    }
                    z = i + 1;
                    while (z < board.size() && board[z][j] == 'X') {
                        board[z][j] = '.';
                        z++;
                    }
                }
            }
        }
        return ship_ct;
    }
};
// @lc code=end

