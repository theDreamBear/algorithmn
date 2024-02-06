/*
 * @lc app=leetcode.cn id=LCR 129 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 129] 字母迷宫
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
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool dfs(vector<vector<char>>& grid, int x, int y, int pos, const string& target) {
        if (pos >= target.size()) {
            return pos >= target.size();
        }
        if (grid[x][y] != target[pos]) {
            return false;
        }
        grid[x][y] = '.';
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y +dy[d];
            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[nx].size() || grid[nx][ny] == '.') {
                continue;
            }
            if (dfs(grid, nx, ny, pos + 1, target)) {
                return true;
            }
        }
        grid[x][y] = target[pos];
        // 当前就是末尾
        return pos + 1 == target.size();
    }

    bool wordPuzzle(vector<vector<char>>& grid, string target) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(grid, i, j, 0, target)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */

