/*
 * @lc app=leetcode.cn id=2639 lang=cpp
 * @lcpr version=30122
 *
 * [2639] 查询网格图中每一列的宽度
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
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        for (int j = 0; j < grid[0].size(); j++) {
            int len = 0;
            for (int i = 0; i < grid.size(); i++) len = max(len, (int)to_string(grid[i][j]).size());
            ans.push_back(len);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1],[22],[333]]\n
// @lcpr case=end

// @lcpr case=start
// [[-15,1,3],[15,7,12],[5,6,-2]]\n
// @lcpr case=end

 */

