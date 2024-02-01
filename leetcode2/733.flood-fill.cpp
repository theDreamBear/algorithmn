/*
 * @lc app=leetcode.cn id=733 lang=cpp
 * @lcpr version=30114
 *
 * [733] 图像渲染
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
    vector<vector<int>> dire = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    void dfs(vector<vector<int>>& ans, vector<vector<int>>& image, int x, int y, int oldColor, int newColor) {
        image[x][y] = -1;
        ans[x][y]   = newColor;
        int m       = image.size();
        int n       = image[0].size();
        for (int d = 0; d < 4; d++) {
            int nx = x + dire[d][0];
            int ny = y + dire[d][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || image[nx][ny] < 0) {
                continue;
            }
            if (image[nx][ny] == oldColor) {
                dfs(ans, image, nx, ny, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill_dfs(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }
        vector<vector<int>> ans      = image;
        int                 m        = image.size();
        int                 n        = image[0].size();
        int                 oldColor = image[sr][sc];

        // image[sr][sc] *= -1; 🙅不行， 因为对于0来说无效
        image[sr][sc] = -1;
        ans[sr][sc]   = color;
        for (int d = 0; d < 4; d++) {
            int nx = sr + dire[d][0];
            int ny = sc + dire[d][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }
            if (image[nx][ny] == oldColor) {
                dfs(ans, image, nx, ny, oldColor, color);
            }
        }
        return ans;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }
        vector<vector<int>>   ans      = image;
        int                   m        = image.size();
        int                   n        = image[0].size();
        int                   oldColor = image[sr][sc];
        queue<pair<int, int>> q;
        ans[sr][sc]   = color;
        image[sr][sc] = -1;
        q.push({sr, sc});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dire[d][0];
                int ny = y + dire[d][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || image[nx][ny] < 0) {
                    continue;
                }
                if (image[nx][ny] == oldColor) {
                    ans[nx][ny]   = color;
                    image[nx][ny] = -1;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1],[1,1,0],[1,0\n1\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,0,0]]\n0\n0\n2\n
// @lcpr case=end

 */
