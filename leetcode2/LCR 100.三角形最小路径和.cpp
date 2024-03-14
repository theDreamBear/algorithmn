/*
 * @lc app=leetcode.cn id=LCR 100 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 100] 三角形最小路径和
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
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int left = j == 0 ? INT_MAX : triangle[i - 1][j - 1];
                int right = j + 1 == triangle[i].size() ? INT_MAX : triangle[i - 1][j];
                triangle[i][j] += min(left, right);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
     }
};
// @lc code=end



/*
// @lcpr case=start
// [[2],[3,4],[6,5,7],[4,1,8,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[-10]]\n
// @lcpr case=end

 */

