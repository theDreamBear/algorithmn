/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 * @lcpr version=30204
 *
 * [1277] 统计全为 1 的正方形子矩阵
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
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() or matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) f[i + 1][j + 1] = 0;
                else {
                    f[i + 1][j + 1] = min({f[i + 1][j], f[i][j + 1], f[i][j]}) + 1;
                }
                ans += f[i + 1][j + 1];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1,1],[1,1,1,1],[0,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

 */

