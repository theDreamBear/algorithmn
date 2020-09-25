/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    struct UnionFound {
        int rows;
        int cols;
        int sz;
        int* fa;
        UnionFound(int rows, int cols) {
            this->rows = rows;
            this->cols = cols;
            sz = rows * cols;
            fa = new int[sz];

            for (int i = 0; i < sz; ++i) {
                fa[i] = i;
            }
        }

        int _find(int pos) {
            if (fa[pos] == pos) {
                return pos;
            }
            fa[pos] = _find(fa[pos]);
            return fa[pos];
        }

        int find(int x, int y) {
            int pos = x * cols + y;
            return _find(pos);
        }
        
        bool isEdge(int pos) {
            int x = pos / cols;
            int y = pos - x * cols;
            if (x * y == 0 || x == rows - 1 || y == cols - 1) {
                return true;
            }
            return false;
        }
        // 合并策略需要更改
        void _merge(int pos1, int pos2) {
            // 粗暴合并
            fa[_find(pos2)] = _find(pos1);
        }

        void merge(int x1, int y1, int x2, int y2) {
            int pos1 = x1 * cols + y1;
            int pos2 = x2 * cols + y2;
            if (isEdge(_find(pos1))) {
                _merge(pos1, pos2);
            } else {
                _merge(pos2, pos1);
            }
            return;
        }
    };

    void solve1(vector<vector<char>>& board) {
        if (board.size() <= 1) {
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        UnionFound uf(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    if (i - 1 >= 0 && board[i - 1][j] == 'O') {
                        uf.merge(i - 1, j, i, j);
                    }
                    if (j - 1 >= 0 && board[i][j - 1] == 'O') {
                        uf.merge(i, j - 1, i, j);
                    }
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    int fa = uf.find(i, j);
                    if (!uf.isEdge(fa)) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
        return;
    }

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0}; 

    void dfs(int i, int j, vector<vector<char>>& board) {
        board[i][j] = 'o';
        for (int offset = 0; offset < 4; ++offset) {
            int newx = i + dx[offset];
            int newy = j + dy[offset];
            if (newx >= 0 && newx < board.size() && newy >= 0 && newy < board[newx].size()) {
                if (board[newx][newy] == 'O') {
                    dfs(newx, newy, board);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() <= 1) {
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i * j == 0 || i == rows - 1 || j == cols - 1) {
                    if (board[i][j] == 'O') {
                        dfs(i, j, board);
                    }
                }
            }
        }
         for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'o') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};
// @lc code=end

