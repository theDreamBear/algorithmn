/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
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
class Solution {
 public:
    int countAlive(const vector<vector<int>>& board, int x, int y) {
        int m = board.size();
        int n = board.back().size();
        int ct = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nx = x + i;
                int ny = y + j;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (board[nx][ny] == 1) {
                    ++ct;
                }
            }
        }
        return ct;
    }

    void gameOfLife(vector<vector<int>>& board) {
        auto temp = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int ct = countAlive(temp, i, j);
                if (temp[i][j] == 0) {
                    if (ct == 3) {
                        board[i][j] = 1;
                    }
                    continue;
                }
                if (ct > 3 || ct < 2) {
                    board[i][j] = 0;
                }
            }
        }
        return;
    }
};
// @lc code=end

