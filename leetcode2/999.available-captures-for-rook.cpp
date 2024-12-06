/*
 * @lc app=leetcode.cn id=999 lang=cpp
 * @lcpr version=30204
 *
 * [999] 可以被一步捕获的棋子数
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
    int numRookCaptures(vector<vector<char>>& board) {
        vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int x, y;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int step = 1; step < 8; step++) {
                int nx = x + dir[i][0] * step;
                int ny = y + dir[i][1] * step;
                if (nx < 0 or nx >= 8 or ny < 0 or ny >= 8 or board[nx][ny] == 'B') break;
                if (board[nx][ny] == 'p') {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]\n
// @lcpr case=end

// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]\n
// @lcpr case=end

// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]\n
// @lcpr case=end

 */

