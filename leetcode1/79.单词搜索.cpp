/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    int dx[4]= {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool exist(vector<vector<char>>& board, string word) {
        function<bool(int, int, int)> backtrack = [&](int x, int y, int pos)->bool {
            if (pos == word.size()) {
                return true;
            }
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[nx].size() || board[nx][ny] == '.' || board[nx][ny] != word[pos]) {
                    continue;
                }
                board[nx][ny] = '.';
                if (backtrack(nx, ny, pos + 1)) {
                    return true;
                }
                board[nx][ny] = word[pos];
            }
            return false;
        };
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '.';
                    if (backtrack(i, j, 1)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};
// @lc code=end

