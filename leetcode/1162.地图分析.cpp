/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */
//#include<set>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int absoluteLength(int x1, int x2) {
        if (x1 > x2) {
            return x1 - x2;
        }
        return x2 - x1;
    }

    int pointAbosoluteLength(int x1, int y1, int x2, int y2) {
        return absoluteLength(x1, x2) + absoluteLength(y1, y2);
    }
    
    // 最近陆地的距离
    int shortestLength(int x, int y,  vector<pair<int, int> >& lands) {
        int result = 0x7fffffff;
        for (int index = 0; index < lands.size(); ++ index) {
            int r = pointAbosoluteLength(x, y, lands[index].first, lands[index].second);
            if (r < result) {
                result = r;
            }
        }
        return result;
    }
    //  暴力求解 超时
    // 时间复杂度 o(n^2)
    int maxDistance_violence(vector<vector<int>>& grid) {
        int result = -1;
        vector<pair<int, int> > lands;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    lands.push_back({i, j});
                }
            }
        }
        if (lands.size() == 0) {
            return result;
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    int r = shortestLength(i, j, lands);
                    if (r > result) {
                        result = r;
                    }
                }
            }
        }
        return result;
    }
    
    //int dx[4] = {0, -1, 0, 1};
    //int dy[4] = {-1, 0, 1, 0};

    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    static constexpr int MAX_N = 100 + 5;
    bool visit[MAX_N][MAX_N];

    void bfs(int x, int y, int& pos, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        memset(visit, 0, sizeof vis);
        q.push({x, y});
        visit[x][y] = true;
        int l = 0;
        while (!q.empty()) {
            int sz = q.size();
            ++l;
            // 层次遍历
            for (int k = 0; k < sz; ++k) {
                auto p = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int newx = p.first + dx[i];
                    int newy = p.second + dy[i];
                    if (newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[newx].size() && !visit[newx][newy]) {
                        if (grid[newx][newy] == 1) {
                            pos = l;
                            return;
                        } else {
                            q.push({newx, newy});
                            visit[newx][newy] = true;
                        }
                    }
                }
            }
        }
        return;
    }
    
    // 每个点宽度有限搜索
    // 超时
    int maxDistance(vector<vector<int>>& grid) {
        int result = -1;
        // 全为 0 或全为 1
        int zeroCount = 0;
        int oneCount = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++zeroCount;
                } else {
                    ++oneCount;
                }
            }
        }
        if (zeroCount * oneCount == 0) {
            return result;
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int r = -1;
                if (grid[i][j] == 0) {
                    bfs(i, j, r, grid);
                    if (r > result) {
                        result = r;
                    }
                }
            }
        }
        return result;
    }


    struct Coordinate {
        int x, y, step;
    };

    int n, m;
    vector<vector<int>> a;
    bool vis[MAX_N][MAX_N];

    int findNearestLand(int x, int y) {
        memset(vis, 0, sizeof vis);
        queue <Coordinate> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) continue;
                if (!vis[nx][ny]) {
                    q.push({nx, ny, f.step + 1});
                    vis[nx][ny] = 1;
                    if (a[nx][ny]) return f.step + 1;
                }
            }
        }
        return -1;
    }
    
    int maxDistance_new2(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid.at(0).size();
        a = grid;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    ans = max(ans, findNearestLand(i, j));
                }
            }
        }
        return ans;
    }

};
// @lc code=end

