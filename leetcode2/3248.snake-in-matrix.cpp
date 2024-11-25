/*
 * @lc app=leetcode.cn id=3248 lang=cpp
 * @lcpr version=30204
 *
 * [3248] 矩阵中的蛇
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
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for (auto str: commands) {
            if (str == "UP") x--;
            else if (str == "DOWN") x++;
            else if (str == "LEFT") y--;
            else {
                y++;
            }
        }
        return x * n + y;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n["RIGHT","DOWN"]\n
// @lcpr case=end

// @lcpr case=start
// 3\n["DOWN","RIGHT","UP"]\n
// @lcpr case=end

 */

