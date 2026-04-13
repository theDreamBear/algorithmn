/*
 * @lc app=leetcode.cn id=2087 lang=cpp
 * @lcpr version=30204
 *
 * [2087] 网格图中机器人回家的最小代价
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minCost1(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        if (startPos == homePos) return 0;
        int ans = 0;
        int x = startPos[0], y = startPos[1];
        int nx = homePos[0], ny = homePos[1];
        if (x <= nx) {
            for (int i = x + 1; i <= nx; i++) {
                ans += rowCosts[i];
            }
        } else {
            for (int i = x - 1; i >= nx; i--) {
                ans += rowCosts[i];
            }
        }
        if (y <= ny) {
            for (int i = y + 1; i <= ny; i++) {
                ans += colCosts[i];
            }
        } else {
            for (int i = y - 1; i >= ny; i--) {
                ans += colCosts[i];
            }
        }
        return ans;
    }

    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        if (startPos == homePos) return 0;
        int x = startPos[0], y = startPos[1];
        int nx = homePos[0], ny = homePos[1];
        int ans = -rowCosts[x] - colCosts[y];
        ans += reduce(rowCosts.begin() + min(x, nx), rowCosts.begin() + max(x, nx) + 1);
        ans += reduce(colCosts.begin() + min(y, ny), colCosts.begin() + max(y, ny) + 1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 0]\n[2, 3]\n[5, 4, 3]\n[8, 2, 6, 7]\n
// @lcpr case=end

// @lcpr case=start
// [0, 0]\n[0, 0]\n[5]\n[26]\n
// @lcpr case=end

 */

