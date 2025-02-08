/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30204
 *
 * [63] 不同路径 II
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
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
         if (g[0][0] == 1 or g[m - 1][n - 1] == 1) {
            return 0;
         }
         g[0][0] = 1;
        // 第一行
        for (int j = 1; j < n; j++) {
            g[0][j] = g[0][j - 1] & !g[0][j];
        }
        for (int i = 1; i < m; i++) {
            g[i][0] = g[i - 1][0] & !g[i][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (g[i][j] == 1) {
                    g[i][j] = 0;
                } else {
                    g[i][j] = g[i - 1][j] + g[i][j - 1];
                }
            }
        }
        return g[m -1][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */

