/*
 * @lc app=leetcode.cn id=3195 lang=cpp
 * @lcpr version=30204
 *
 * [3195] 包含所有 1 的最小矩形面积 I
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
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int top = -1, bot = m, left = -1, right = n;
        bool found = false;
        for (int i = 0; i < m and !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    found = true;
                    top = i;
                    break;
                }
            }
        }
        if (top == -1) return 0;

        found = false;
        for (int i = m - 1; i >= top and !found; i--) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    found = true;
                    bot = i;
                    break;
                }
            }
        }
        found = false;
        for (int j = 0; j < n and !found; j++) {
            for (int i = top; i <= bot; i++) {
                if (grid[i][j]) {
                    found = true;
                    left = j;
                }
            }
        }
        found = false;
        for (int j = n - 1; j >= left and !found; j--) {
            for (int i = top; i <= bot; i++) {
                if (grid[i][j]) {
                    found = true;
                    right = j;
                }
            }
        }
        return (bot - top + 1) * (right - left + 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,0],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,0]]\n
// @lcpr case=end

 */

