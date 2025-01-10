/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 * @lcpr version=30204
 *
 * [1030] 距离顺序排列矩阵单元格
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
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        vector<vector<int>> vis(rows, vector<int>(cols));
        // bfs
        queue<pair<int, int>> q;
        vis[rCenter][cCenter] = 1;
        q.push({rCenter, cCenter});
        ans.push_back({rCenter, cCenter});
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = r + dx[k];
                int ny = c + dy[k];
                if (nx < 0 or nx >= rows or ny < 0 or ny >= cols or vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.push({nx, ny});
                ans.push_back({nx, ny});
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n2\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n0\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n1\n2\n
// @lcpr case=end

 */

