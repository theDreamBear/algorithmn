/*
 * @lc app=leetcode.cn id=LCR 107 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 107] 01 矩阵
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
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { -1, 0, 1, 0 };

    // 超时
    vector<vector<int>> updateMatrix_bad(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    continue;
                }
                int d = 0;
                vector<int> vis(m * n, 0);
                queue<int> q;
                q.push(i * n + j);
                vis[i * n + j] = 1;
                bool found = false;
                while (!q.empty() and !found) {
                    d++;
                    int sz = q.size();
                    while (sz-- and !found) {
                        auto node = q.front();
                        q.pop();
                        int x = node / n;
                        int y = node % n;
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx * n + ny]) {
                                continue;
                            }
                            if (mat[nx][ny] == 0) {
                                ans[i][j] = d;
                                found = true;
                                break;
                            }
                            q.push(nx * n + ny);
                        }
                    }
                }
            }
        }
        return ans;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> vis(m * n, 0);
        queue<int> q;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push(i * n + j);
                    vis[i * n + j] = 1;
                }

            }
        }
        int d = 0;
        while (!q.empty()) {
            d++;
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                q.pop();
                int x = node / n;
                int y = node % n;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx * n + ny]) {
                        continue;
                    }
                    ans[nx][ny] = d;
                    q.push(nx * n + ny);
                    vis[nx * n + ny] = 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,1,0],[1,1,1]]\n
// @lcpr case=end

 */

