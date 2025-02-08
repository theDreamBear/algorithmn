/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30204
 *
 * [59] 螺旋矩阵 II
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int val = 1;
        int top = 0, bot = n - 1, left = 0, right = n - 1;
        while (true) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = val++;
            }
            top++;
            if (top > bot) {
                break;
            }
            for (int i = top; i <= bot; i++) {
                ans[i][right] = val++;
            }
            right--;
            if (left > right) {
                break;
            }
            for (int i = right; i >= left; i--) {
                ans[bot][i] = val++;
            }
            bot--;
            if (top > bot) {
                break;
            }
            for (int i = bot; i >= top; i--) {
                ans[i][left] = val++;
            }
            left++;
            if (left > right) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

