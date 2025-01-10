/*
 * @lc app=leetcode.cn id=883 lang=cpp
 * @lcpr version=30204
 *
 * [883] 三维形体投影面积
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
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid[0].size();
        vector<int> ma(m);
        for (auto& vec: grid) {
            ans += ranges::max(vec);
            for (int j = 0; j < vec.size(); j++) {
                if (vec[j] != 0) ans++;
                ma[j] = max(ma[j], vec[j]);
            }
        }
        return ans + reduce(ma.begin(), ma.end(), 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0],[0,2]]\n
// @lcpr case=end

 */

