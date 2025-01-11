/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 * @lcpr version=30204
 *
 * [1232] 缀点成线
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
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.size(); i++) {
            int x3 = coordinates[i][0], y3 = coordinates[i][1];
            int d1 = x2 - x1, d2 = x3 - x1;
            int k1 = y2 - y1, k2 = y3 - y1;
            if (d1 * k2 != d2 * k1) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]\n
// @lcpr case=end

 */

