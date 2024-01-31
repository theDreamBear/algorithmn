/*
 * @lc app=leetcode.cn id=289 lang=cpp
 * @lcpr version=30114
 *
 * [289] 生命游戏
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
    vector<pair<int, int>> direction = {
        {0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
        {0, 1}, {1, 1}, {1, 0}, {1, -1},
    };

    /*
        时间复杂度： O(m * n * 8)
        空间复杂度： O(m * n);
    */
    void gameOfLife1(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        auto next = board;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveCt = 0;
                for (int d = 0; d < 8; d++) {
                    int nx = i + direction[d].first;
                    int ny = j + direction[d].second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }
                    if (board[nx][ny]) {
                        liveCt++;
                    }
                }
                if (board[i][j]) {
                    if (liveCt < 2 || liveCt > 3) {
                        next[i][j] = 0;
                    }
                } else if (liveCt == 3) {
                    next[i][j] = 1;
                }
            }
        }
        board = move(next);
        return;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        enum {
            DEAD = 0,
            LIVE = 1,
            USEDTOLIVE = 2,
            USEDTODEAD = 3,
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveCt = 0;
                for (int d = 0; d < 8; d++) {
                    int nx = i + direction[d].first;
                    int ny = j + direction[d].second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }
                    if (board[nx][ny] == LIVE || board[nx][ny] == USEDTOLIVE) {
                        liveCt++;
                    }
                }
                if (board[i][j] == LIVE) {
                    if (liveCt < 2 || liveCt > 3) {
                        board[i][j] = USEDTOLIVE;
                    }
                } else if (liveCt == 3) {
                    board[i][j] = USEDTODEAD;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == USEDTOLIVE || board[i][j] == USEDTODEAD) {
                    board[i][j] -= 2;
                }
            }
        }
        return;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,0]]\n
// @lcpr case=end

 */

