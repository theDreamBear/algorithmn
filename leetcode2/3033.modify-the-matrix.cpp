/*
 * @lc app=leetcode.cn id=3033 lang=cpp
 * @lcpr version=30204
 *
 * [3033] 修改矩阵
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
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> cols(n, -1);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                cols[j] = max(cols[j], matrix[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == -1) matrix[i][j] = cols[j];
            }
        }
        return matrix;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,-1],[4,-1,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,-1],[5,2]]\n
// @lcpr case=end

 */

