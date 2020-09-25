/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    struct UnionQuery {
        int m, n;
        int* fa;
        int count;

        UnionQuery(int m, int n) {
            this->m = m;
            this->n = n;
            fa = new int[m * n];
            count = 0;
            for (int i = 0; i < m * n; ++i) {
                fa[i] = i;
            }
        }

        ~UnionQuery() {
            delete []fa;
        }

        int _find(int pos) {
            if (pos == fa[pos]) {
                return pos;
            }
            // 压缩
            fa[pos] = _find(fa[pos]);
            return fa[pos];
        }

        int find(int x, int y) {
           return _find(x * n + y);
        }

        void merge(int x1, int y1, int x2, int y2) {
            int p1 = find(x1, y1);
            int p2 = find(x2, y2);
            if (p1 == p2) {
                return;
            }
            decreseCount();
            fa[p2] = p1; 
        }

        void increseCount() {
            ++count;
        }

        void decreseCount() {
            --count;
        }

        int getCount() {
            return count;
        }
    };
    // 并查集
    int numIslands1(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        UnionQuery uq(grid.size(), grid[0].size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    uq.increseCount();
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                        uq.merge(i - 1, j, i, j);
                    } 
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                        uq.merge(i, j - 1, i, j);
                    }
                }
            }
        }
        return uq.getCount();
    }

    // bfs
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        queue<pair<int, int>> q;
        int ct = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    q.push({i, j});
                    while(!q.empty()) {
                        auto node = q.front();
                        q.pop();
                        int x = node.first;
                        int y = node.second;
                        // 广度
                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                            q.push({x - 1, y});
                            grid[x - 1][y] = '0';
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                            q.push({x, y - 1});
                            grid[x][y - 1] = '0';
                        }

                        if (x + 1 < grid.size() && grid[x + 1][y] == '1') {
                            q.push({x + 1, y});
                            grid[x + 1][y] = '0';
                        }
                        if (y + 1 < grid[x].size() && grid[x][y + 1] == '1') {
                            q.push({x, y + 1});
                            grid[x][y + 1] = '0';
                        }
                    }
                    ++ct;
                }
            }
        }
        return ct;
    }
};
// @lc code=end

