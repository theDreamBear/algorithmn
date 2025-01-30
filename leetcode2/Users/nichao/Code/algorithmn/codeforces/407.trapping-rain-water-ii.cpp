/*
 * @lc app=leetcode.cn id=407 lang=cpp
 * @lcpr version=30204
 *
 * [407] 接雨水 II
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
    int trapRainWater(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        if (m <= 1 or n <= 1) {
            return 0;
        }
        // 边界洪泛
        auto cmp = [&](auto& a, auto& b) {
            return g[a.first][a.second] < g[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        // 边界入队列
        for (int i = 0; i < n; i++) {
            g[0][i] = -g[0][i] - 1;
            g[m - 1][i] = -g[m - 1][i] - 1;
            pq.emplace(0, i);
            pq.emplace(m - 1, i);
        }
        for (int i = 1; i + 1 < m; i++) {
            g[i][0] = -g[i][0] - 1;
            g[i][n - 1] = -g[i][n - 1] - 1;
            pq.emplace(i, 0);
            pq.emplace(i, n - 1);
        }
        int dx[4]{0, -1, 0, 1};
        int dy[4]{-1, 0, 1, 0};
        int ans = 0;
        while (!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            auto d = -g[x][y];
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 or nx >= m or ny < 0 or ny >= n or g[nx][ny] < 0) {
                    continue;
                }
                ans += max(0, d - g[nx][ny] - 1);
                g[nx][ny] = min(g[x][y], -g[nx][ny] - 1);
                pq.emplace(nx, ny);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]\n
// @lcpr case=end

 */

