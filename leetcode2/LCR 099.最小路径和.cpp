/*
 * @lc app=leetcode.cn id=LCR 099 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 099] 最小路径和
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
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < grid[0].size(); j++) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[i].size(); j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid.back().back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */

