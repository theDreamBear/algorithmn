/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution1 {
public:
    int totalNQueens(int n) {
        int ans = 0;
        int upperLimit = (1 << n) - 1;
        function<void(int, int ,int)> backtrack = [&](int num, int ll, int rr) {
            if (num == upperLimit) {
                ++ans;
                return;
            }
            int mask = upperLimit & ~(ll | rr | num);
            while (mask > 0) {
                int v = mask & ~(mask - 1);
                backtrack(num ^ v, (ll ^ v) << 1, (rr ^ v) >> 1);
                mask ^= v;
            }
        };
        backtrack(0, 0, 0);
        return ans;
    }
};

void flagSet(int n, int i, int j, vector<vector<int>>& board, int origin,  int des) {
    // 置位
    // 按照 当前位置为顶点, 进行 "个" 字置位
    // 左斜
    for (int dx = 1, dy = -1, nx = i, ny = j; nx < n && ny >= 0; nx += dx, ny += dy) {
        if (board[nx][ny] == origin) {
            board[nx][ny] = des;
        }
    }
    // 竖线
    for (int dx = 1, dy = 0, nx = i, ny = j; nx < n && ny >= 0; nx += dx, ny += dy) {
        if (board[nx][ny] == origin) {
            board[nx][ny] = des;
        }
    }
    // 右斜
    for (int dx = 1, dy = 1, nx = i, ny = j; nx < n && ny < n; nx += dx, ny += dy) {
        if (board[nx][ny] == origin) {
            board[nx][ny] = des;
        }
    }
    //print(board);
}

void flagSet(int n, int i, int j, vector<vector<int>>& board) {
    // 置位
    // 按照 当前位置为顶点, 进行 "个" 字置位
    // 左斜
    for (int dx = 1, dy = -1, nx = i, ny = j; nx < n && ny >= 0; nx += dx, ny += dy) {
        board[nx][ny] = 1;
    }
    // 竖线
    for (int dx = 1, dy = 0, nx = i, ny = j; nx < n && ny >= 0; nx += dx, ny += dy) {
        board[nx][ny] = 1;
    }
    // 右斜
    for (int dx = 1, dy = 1, nx = i, ny = j; nx < n && ny < n; nx += dx, ny += dy) {
        board[nx][ny] = 1;
    }
}

void totalNQueensDfs(const int n,  int x, vector<vector<int>>& board, int& ans) {
    if (x > n) {
        return;
    }
    if (x + 1 == n) {
        ++ans;
        //print(board);
        return;
    }
    for (int i = x + 1, j = 0; i < n && j < n; j++) {
        if (board[i][j]) {
            continue;
        }
//        auto nb = board;
        // 置位
        flagSet(n, i, j, board, 0, i * n + j + 1);
        // 递归
        totalNQueensDfs(n, i, board, ans);
        // 回溯
        flagSet(n, i, j, board, i * n + j + 1, 0);
    }
}

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<vector<int>> board(n, vector<int>(n));
        totalNQueensDfs(n, -1, board, ans);
        return ans;
    }
};

// @lc code=end

