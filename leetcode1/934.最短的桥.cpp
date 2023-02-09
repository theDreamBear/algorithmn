/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */
#include <vector>
#include <set>
#include <queue>
using namespace std;
// @lc code=start
class Solution1 {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<pair<int, int>> _findFirstIsland(const vector<vector<int>>& grid) {
        vector<pair<int, int>> ans;
        int x, y;
        bool found = false;
        set<pair<int, int>> visited;
        for (int i = 0; i < grid.size(); i++) {
            for  (int j = 0; !found && j < grid[i].size(); j++) {
                visited.insert({i, j});
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                    found = true;
                    break;
                }
            }
        }
        ans.push_back({x, y});
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                // 不能越界
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[nx].size()) {
                    continue;
                }
                // 0 或者 不能二次加入
                if (grid[nx][ny] == 0 ||  visited.count({nx, ny})) {
                    continue;
                }
                visited.insert({nx, ny});
                q.push({nx, ny});
                ans.push_back({nx, ny});
            }
        }
        return ans;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        auto first = _findFirstIsland(grid);
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        for (auto& v : first) {
            q.push(v);
            visited.insert(v);
        }
        int ans = -1;
        bool finish = false;
        while (!finish && !q.empty()) {
            ++ans;
            int sz = q.size();
            for (int idx = 0; idx < sz; idx++) {
                auto [i, j] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    // 不能越界
                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[nx].size()) {
                        continue;
                    }
                    if (visited.count({nx, ny})) {
                        continue;
                    }
                    if (grid[nx][ny] == 1) {
                        finish = true;
                        break;
                    }
                    q.push({nx, ny});
                    visited.insert({nx, ny});
                }
            }
        }
        return ans;
    }
};

class Solution2 {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<pair<int, int>> _findFirstIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> ans;
        int x, y;
        bool found = false;
        for (int i = 0; i < grid.size(); i++) {
            for  (int j = 0; !found && j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                    found = true;
                    break;
                }
            }
        }
        ans.push_back({x, y});
        grid[x][y] = -1;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                // 不能越界
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[nx].size()) {
                    continue;
                }
                // 0 或者 不能二次加入
                if (grid[nx][ny] != 1) {
                    continue;
                }
                q.push({nx, ny});
                grid[nx][ny] = -1;
                ans.push_back({nx, ny});
            }
        }
        return ans;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        auto first = _findFirstIsland(grid);
        queue<pair<int, int>> q;
        for (auto& v : first) {
            q.push(v);
        }
        int ans = -1;
        bool finish = false;
        while (!finish && !q.empty()) {
            ++ans;
            int sz = q.size();
            for (int idx = 0; idx < sz; idx++) {
                auto [i, j] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    // 不能越界
                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[nx].size()) {
                        continue;
                    }
                    if (grid[nx][ny] == -1) {
                        continue;
                    }
                    if (grid[nx][ny] == 1) {
                        finish = true;
                        break;
                    }
                    q.push({nx, ny});
                    grid[nx][ny] = -1;
                }
            }
        }
        return ans;
    }
};

class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        // 加入的时候改
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return;
            }
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                // 不能越界
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) {
                    continue;
                }
                q.push({nx, ny});
                grid[nx][ny] = -1;
                dfs(nx, ny);
            }
        };
        bool found = false;
        for (int i = 0; i < grid.size(); i++) {
            for  (int j = 0; !found && j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = -1;
                    dfs(i, j);
                    found = true;
                }
            }
        }
        int ans = -1;
        bool finish = false;
        while (!finish && !q.empty()) {
            ++ans;
            int sz = q.size();
            for (int idx = 0; idx < sz; idx++) {
                auto [i, j] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    // 不能越界
                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[nx].size()) {
                        continue;
                    }
                    if (grid[nx][ny] == -1) {
                        continue;
                    }
                    if (grid[nx][ny] == 1) {
                        finish = true;
                        break;
                    }
                    q.push({nx, ny});
                    grid[nx][ny] = -1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

