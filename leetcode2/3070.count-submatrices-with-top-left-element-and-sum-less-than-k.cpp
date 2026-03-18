/*
 * @lc app=leetcode.cn id=3070 lang=cpp
 * @lcpr version=30204
 *
 * [3070] 元素和小于等于 k 的子矩阵的数目
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
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] + grid[i][j] - sum[i][j];
                if (sum[i + 1][j + 1] <= k) ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,6,3],[6,6,1]]\n18\n
// @lcpr case=end

// @lcpr case=start
// [[7,2,9],[1,5,0],[2,6,6]]\n20\n
// @lcpr case=end

 */

