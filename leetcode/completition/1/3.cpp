#include <math.h>

#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
    // 神奇的左右腾挪大法
    int minimumEffortPath_magic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9));
        dp[0][0] = 0;

        int t = max(heights.size(), heights[0].size()) / 2 + 1;
        for (int times = 0; times < t; ++times) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0 && max(dp[i - 1][j],
                                     abs(heights[i][j] - heights[i - 1][j])) <
                                     dp[i][j]) {
                        dp[i][j] = max(dp[i - 1][j],
                                       abs(heights[i][j] - heights[i - 1][j]));
                    }
                    if (j > 0 && max(dp[i][j - 1],
                                     abs(heights[i][j] - heights[i][j - 1])) <
                                     dp[i][j]) {
                        dp[i][j] = max(dp[i][j - 1],
                                       abs(heights[i][j] - heights[i][j - 1]));
                    }
                }
            }
            for (int i = m - 1; i >= 0; --i) {
                for (int j = n - 1; j >= 0; --j) {
                    if (i < m - 1 &&
                        max(dp[i + 1][j], abs(heights[i][j] -
                                              heights[i + 1][j])) < dp[i][j]) {
                        dp[i][j] = max(dp[i + 1][j],
                                       abs(heights[i][j] - heights[i + 1][j]));
                    }
                    if (j < n - 1 &&
                        max(dp[i][j + 1], abs(heights[i][j] -
                                              heights[i][j + 1])) < dp[i][j]) {
                        dp[i][j] = max(dp[i][j + 1],
                                       abs(heights[i][j] - heights[i][j + 1]));
                    }
                }
            }
            // print(dp);
        }

        return dp[m - 1][n - 1];
    }

    constexpr static int dx[] = {0, -1, 0, 1};
    constexpr static int dy[] = {-1, 0, 1, 0};
    // 从 （i， j）到终点的最短距离
    //** 更新顺序错误
    int dfs(int i, int j, const vector<vector<int>>& heights,
            vector<vector<bool>>& used) {
        if (i == heights.size() - 1 && j == heights[0].size() - 1) {
            return 0;
        }
        used[i][j] = true;
        int now = INT_MAX;
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            // used[nx][ny]不要会无限递归 ，要了结果就错了
            if (nx < 0 || nx >= heights.size() || ny < 0 ||
                ny >= heights[0].size() || used[nx][ny]) {
                continue;
            }
            int path = max(abs(heights[i][j] - heights[nx][ny]),
                           dfs(nx, ny, heights, used));
            now = min(now, path);
        }
        used[i][j] = false;
        return now;
    }

    int minimumEffortPath_dfs(vector<vector<int>>& heights) {
        vector<vector<bool>> used(heights.size(),
                                  vector<bool>(heights[0].size(), false));
        int ans = dfs(0, 0, heights, used);
        return ans;
    }

    bool binary_dfs(int i, int j, vector<vector<int>>& heights, int limit,
                    vector<vector<bool>>& used) {
        if (i == heights.size() - 1 && j == heights[0].size() - 1) {
            return true;
        }
        used[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || nx >= heights.size() || ny < 0 ||
                ny >= heights[0].size() || used[nx][ny]) {
                continue;
            }
            if (abs(heights[i][j] - heights[nx][ny]) <= limit) {
                if (binary_dfs(nx, ny, heights, limit, used)) {
                    return true;
                }
            }
        }
        // 精髓不回溯
        // used[i][j] = false;
        return false;
    }

    void reset(vector<vector<bool>>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                vec[i][j] = false;
            }
        }
    }

    /*
    二分 + dfs
    */
    int minimumEffortPath_binary_dfs(vector<vector<int>>& heights) {
        int left = 0, right = 999999;
        vector<vector<bool>> used(heights.size(),
                                  vector<bool>(heights[0].size(), false));
        while (left < right) {
            int mid = (left + right) / 2;
            if (binary_dfs(0, 0, heights, mid, used)) {
                right = mid;
            } else {
                left = mid + 1;
            }
            reset(used);
        }
        return left;
    }

      int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int left = 0, right = 1e6;
        while (left < right) {
            int mid = (left + right) >> 1;
            queue<pair<int, int>> q;
            vector<vector<bool>> seen(m, vector<bool>(n, false));
            q.emplace(0, 0);
            seen[0][0] = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                //int x = cur.first;
                //int y = cur.second;
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx][ny] && abs(heights[nx][ny] - heights[x][y]) <= mid) {
                        q.emplace(nx, ny);
                        seen[nx][ny] = true;
                    }
                }
            }
            if (seen[m - 1][n -1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
        
    }

    struct node {
        int x, y;
    };

    // dfs 超时， 不考虑了，下面bfs
    int minimumEffortPath_bfs(vector<vector<int>>& heights) {
        queue<node> st;
        st.push({0, 0});
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> used(r, vector<int>(c, INT_MAX));
        used[0][0] = 0;
        while (!st.empty()) {
            int sz = st.size();
            for (int i = 0; i < sz; ++i) {
                auto n = st.front();
                st.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = n.x + dx[k];
                    int ny = n.y + dy[k];
                    if (nx < 0 || nx >= heights.size() || ny < 0 ||
                        ny >= heights[0].size()) {
                        continue;
                    }
                    int new_diff = max(abs(heights[nx][ny] - heights[n.x][n.y]),
                                       used[n.x][n.y]);
                    // 只有更新的节点才需要添加进去， 不然会无限递归
                    if (new_diff < used[nx][ny]) {
                        used[nx][ny] = new_diff;
                        st.push({nx, ny});
                    }
                }
            }
        }
        return used[r - 1][c - 1];
    }
};

int main() {
    vector<vector<vector<int>>> data;

    // vector<vector<int>> d1 = {{1, 2, 1, 1, 1},
    //                           {1, 2, 1, 2, 1},
    //                           {1, 2, 1, 2, 1},
    //                           {1, 2, 1, 2, 1},
    //                           {1, 1, 1, 2, 1}};

    vector<vector<int>> d2 = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};

    data.push_back(d2);

    cout << Solution{}.minimumEffortPath(d2) << endl;
}