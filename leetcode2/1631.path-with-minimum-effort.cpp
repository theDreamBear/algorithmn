/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 * @lcpr version=30204
 *
 * [1631] 最小体力消耗路径
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 题目读错了, 呜呜呜
    int minimumEffortPath_bad(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> cost(m, vector<int>(n));
        cost[0][0] = 0;
        for (int i = 1; i < m; i++) {
            cost[i][0] = max(cost[i - 1][0], abs(heights[i][0] - heights[i - 1][0]));
        }
        for (int j = 1; j < n; j++) {
            cost[0][j] = max(cost[0][j - 1], abs(heights[0][j] - heights[0][j - 1]));
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cost[i][j] = min(max(cost[i - 1][j], abs(heights[i][j] - heights[i - 1][j])), max(cost[i][j - 1], abs(heights[i][j] - heights[i][j - 1])));
            }
        }
        return cost[m - 1][n - 1];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX / 2));
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        int dx[4]{0, -1, 0, 1};
        int dy[4]{-1, 0, 1, 0};
        while (!pq.empty()) {
            auto [x, y, w] = pq.top();
            pq.pop();
            if (dis[x][y] < w) {
                continue;
            }
            if (x == m - 1 and y == n - 1) return w;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 or nx >= m or ny < 0 or ny >= n) {
                    continue;
                }
                if (dis[nx][ny] > max(w, abs(heights[x][y] - heights[nx][ny]))) {
                    dis[nx][ny] = max(w, abs(heights[x][y] - heights[nx][ny]));
                    pq.push({nx, ny, dis[nx][ny]});
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,2],[3,8,2],[5,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[3,8,4],[5,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]\n
// @lcpr case=end

 */

