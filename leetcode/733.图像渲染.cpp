/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
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

using namespace std;

// @lc code=start
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    /*
        深度优先遍历
    */
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor) {
        if (image[x][y] != oldColor) {
            return;
        }
        image[x][y] = newColor;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= image.size() || ny < 0 || ny >= image[nx].size() || image[nx][ny] != oldColor) {
                continue;
            }
            dfs(image, nx, ny, oldColor, newColor);
        }
        return;
    }

    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    /*
        宽度优先遍历
    */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        int oldColor = image[sr][sc];
        int cols = image[0].size();
        queue<int> q;
        q.push(sr * cols + sc);
        while (!q.empty()) {
            int x = q.front() / cols;
            int y = q.front() % cols;
            q.pop();
            image[x][y] = newColor;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= image.size() || ny < 0 || ny >= image[nx].size() || image[nx][ny] != oldColor) {
                    continue;
                }
                q.push(nx * cols + ny);
            }
        }
        return image;
    }
};
// @lc code=end

