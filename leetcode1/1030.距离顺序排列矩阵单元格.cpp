/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;

        vector<vector<int>> grid(rows, vector<int>(cols));
        int base = 1000;
        queue<int> q;

        int val = rCenter * base + cCenter;
        q.push(val);
        ans.push_back({rCenter, cCenter});
        grid[rCenter][cCenter] = 1;

        int distance = -1;
        while (!q.empty()) {
            ++distance;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                val = q.front();
                q.pop();
                int x = val / base;
                int y = val % base;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || grid[nx][ny] != 0) {
                        continue;
                    }
                    val = nx * base + ny;
                    q.push(val);
                    ans.push_back({nx, ny});
                    grid[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

