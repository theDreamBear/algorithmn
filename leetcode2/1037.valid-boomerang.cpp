/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 * @lcpr version=30204
 *
 * [1037] 有效的回旋镖
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
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        int d1 = x2 - x3, d2 = x1 - x3;
        int k1 = y2 - y3, k2 = y1 - y3;
        return d1 * k2 != k1 * d2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1],[2,3],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,3]]\n
// @lcpr case=end

 */

