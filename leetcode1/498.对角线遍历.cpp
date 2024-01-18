/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
public:
  int dx[2] = {-1, 1};
    int dy[2] = {1, -1};

    bool isValid(int nx, int ny, int m, int n) {
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            return false;
        }
        return true;
    }

    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans(m * n);
        int k = 0;
        int x = 1, y = -1;
        int idx = 0;
        while (idx < m * n) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!isValid(nx, ny, m, n)) {
                if (k == 0) {
                    nx += 1;
                    k = 1;
                } else {
                    ny += 1;
                    k = 0;
                }
            }
            if (isValid(nx, ny, m, n)) {
                ans[idx++] = mat[nx][ny];
            }
            x = nx;
            y = ny;
        }
        return ans;
    }
};
// @lc code=end

