/*
 * @lc app=leetcode.cn id=2711 lang=cpp
 * @lcpr version=30204
 *
 * [2711] 对角线上不同值的数量差
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
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 左上角
                unordered_set<int> top;
                int dx = -1, dy = -1;
                int x = i + dx, y = j + dy;
                while (x >= 0 and y >= 0) {
                    top.insert(grid[x][y]);
                    x += dx;
                    y += dy;
                }
                // 右下角
                unordered_set<int> bot;
                dx = 1, dy = 1;
                x = i + dx, y = j + dy;
                while (x < m and y < n) {
                    bot.insert(grid[x][y]);
                    x += dx;
                    y += dy;
                }
                ans[i][j] = abs((int)top.size() - (int)bot.size());
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[3,1,5],[3,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */

