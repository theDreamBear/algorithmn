/*
 * @lc app=leetcode.cn id=3643 lang=cpp
 * @lcpr version=30204
 *
 * [3643] 垂直翻转子矩阵
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
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int i = x, j = x + k - 1; i < j; i++, j--) {
            for (int t = y; t < y + k; t++) {
                swap(grid[i][t], grid[j][t]);
            }
        }
        return grid;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]\n1\n0\n3\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,2,3],[2,3,4,2]]\n0\n2\n2\n
// @lcpr case=end

 */

