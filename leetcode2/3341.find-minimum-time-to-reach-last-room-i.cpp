/*
 * @lc app=leetcode.cn id=3341 lang=cpp
 * @lcpr version=30204
 *
 * [3341] 到达最后一个房间的最少时间 I
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
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        using pi = pair<int, int>;
        priority_queue<pi, vector<pi>, greater<>> pq;
        pq.push({0, 0});
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            int x = u / n, y = u % n;
            if (dis[x][y] < d) continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                int nv = max(d + 1, moveTime[nx][ny] + 1);
                if (nv < dis[nx][ny]) {
                    dis[nx][ny] = nv;
                    pq.push({nv, nx * n + ny});
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,4],[4,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2]]\n
// @lcpr case=end

 */

