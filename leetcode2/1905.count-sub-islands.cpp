/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 * @lcpr version=30114
 *
 * [1905] 统计子岛屿
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

    int countSubIslands_bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ct = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[i].size(); j++) {
                if (grid2[i][j] and grid1[i][j]) {
                    queue<int> q;
                    grid2[i][j] = 0;
                    q.push(i * 500 + j);
                    bool flag = true;
                    while (!q.empty()) {
                        auto v = q.front();
                        q.pop();
                        int x = v / 500;
                        int y = v % 500;
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if (nx < 0 || ny < 0 || nx >= grid2.size() || ny >= grid2[nx].size() || !grid2[nx][ny]) {
                                continue;
                            }
                            if (!grid1[nx][ny]) {
                                flag = false;
                            }
                            grid2[nx][ny] = 0;
                            q.push(nx * 500 + ny);
                        }
                    }
                    ct += flag;
                }
            }
        }
        return ct;
    }

    void dfs(bool& flag, int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        grid2[x][y] = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= grid2.size() || ny >= grid2[nx].size() || !grid2[nx][ny]) {
                    continue;
            }
            if (!grid1[nx][ny]) {
                flag = false;
            }
            grid2[nx][ny] = 0;
            dfs(flag, nx, ny, grid1, grid2);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ct = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[i].size(); j++) {
                if (grid2[i][j] and grid1[i][j]) {
                    bool flag = true;
                    dfs(flag, i, j, grid1, grid2);
                    ct += flag;
                }
            }
        }
        return ct;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]\n[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]]\n[[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]\n
// @lcpr case=end

 */

