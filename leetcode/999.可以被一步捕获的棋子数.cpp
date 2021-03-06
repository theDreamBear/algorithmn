/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 可以被一步捕获的棋子数
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int numRookCaptures(vector<vector<char>>& board) {
        int r = 0, c = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        int ct = 0;
        for (int k = 0; k < 4; ++k) {
            int x = r, y = c;
            while (x >= 0 && x < board.size() && y >= 0 && y < board[x].size()) {
                if (board[x][y] == 'B') {
                    break;
                } else if (board[x][y] == 'p') {
                    ++ct;
                    break;
                }
                x += dx[k];
                y += dy[k];
                
            }
        }
        return ct;
    }
};
// @lc code=end

