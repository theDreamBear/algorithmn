/*
 * @lc app=leetcode.cn id=749 lang=cpp
 *
 * [749] 隔离病毒
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
private:
    int m, n;
    vector<vector<int>>* matrix;
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, int& need, unordered_set<int>& dangerousArea, unordered_set<int>& nearDangerousArea, vector<vector<bool>>& visited) {
        visited[x][y] = true;
        dangerousArea.insert(x * n + y);
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nv = nx * n + ny;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] || (*matrix)[nx][ny] == -1) {
                continue;
            }
            if ((*matrix)[nx][ny] == 0) {
                if (nearDangerousArea.count(nv) == 0) {
                    nearDangerousArea.insert(nv);
                }
                ++need;
                continue;
            }
            dfs(nx, ny, need, dangerousArea, nearDangerousArea, visited);
        }
    }

    int getThreatMostArea() {
        int gt = INT_MIN;
        int ans = INT_MIN;
        unordered_set<int> mostNear;
        unordered_set<int> mostDanger;
        unordered_set<int> nextNear;

        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0 ; j < n; ++j) {
                if (!visited[i][j] && (*matrix)[i][j] == 1) {
                    int need = 0;
                    unordered_set<int> danger;
                    unordered_set<int> near;
                    dfs(i, j, need, danger, near, visited);
                    if ((int)near.size() > gt) {
                        gt = near.size();
                        ans = need;
                        mostDanger = danger;
                        for (auto v : mostNear) {
                            nextNear.insert(v);
                        }
                        mostNear = near;
                    } else {
                        for (auto v : near) {
                            nextNear.insert(v);
                        }
                    }
                }
            }
        }
        for(auto v : mostDanger) {
            int x = v / n;
            int y = v % n;
            (*matrix)[x][y] = -1;
        }

        for(auto v : nextNear) {
            int x = v / n;
            int y = v % n;
            (*matrix)[x][y] = 1;
        }
        return ans;
    }

    int containVirus(vector<vector<int>> &isInfected) {
        m = isInfected.size();
        n = isInfected.back().size();
        matrix = &isInfected;
        int ans = 0, t;
        while ((t = getThreatMostArea()) != INT_MIN) {
            ans += t;
        }
        return ans;
    }
};
// @lc code=end

