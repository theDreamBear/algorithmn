/*
 * @lc app=leetcode.cn id=892 lang=cpp
 * @lcpr version=30204
 *
 * [892] 三维形体的表面积
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
    int surfaceArea(vector<vector<int>>& grid) {
        int sub = 0;
        int total = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j  = 0; j < grid[i].size(); j++) {
                if (!grid[i][j]) continue;
                sub += (grid[i][j] - 1) * 2;
                total += grid[i][j];
                // 上下
                if (i > 0) sub += min(grid[i - 1][j], grid[i][j]);
                if (i + 1 < grid.size()) sub += min(grid[i + 1][j], grid[i][j]);
                // 左右
                if (j > 0) sub += min(grid[i][j - 1], grid[i][j]);
                if (j + 1 < grid[i].size()) sub += min(grid[i][j + 1], grid[i][j]);
            }
        }
        return total * 6 - sub;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,2,2],[2,1,2],[2,2,2]]\n
// @lcpr case=end

 */

