/*
 * @lc app=leetcode.cn id=52 lang=cpp
 * @lcpr version=30204
 *
 * [52] N 皇后 II
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
    int totalNQueens(int n) {
        int upper = (1 << n) - 1;
        auto dfs = [&](auto&& dfs, int l, int r, int mask) {
            if (mask == upper) return 1;
            auto val = (~(l | r | mask)) & upper;
            int res  = 0;
            while (val) {
                int v = val & (-val); 
                val -= v;
                res += dfs(dfs,  (l | v) << 1, (r | v) >> 1, mask | v);
            }
            return res;
        };
        return dfs(dfs, 0, 0, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

