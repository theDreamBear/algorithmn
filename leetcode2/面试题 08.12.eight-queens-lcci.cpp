/*
 * @lc app=leetcode.cn id=面试题 08.12 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.12] 八皇后
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
    vector<vector<string>> solveNQueens(int n) {
        vector<string> res;
        vector<vector<string>> ans;
        int upperLimit = (1 << n) - 1;
        auto dfs = [&](auto&&dfs, int i, int ld, int rd, int v) {
            if (i >= n) {
                ans.push_back(res);
                return;
            }
            int left = ~(ld | rd | v) & upperLimit;
            while (left) {
                auto lb = left & -left;
                int p = __lg(lb);
                string tmp = string(p, '.') + 'Q' + string(n - p - 1, '.');
                res.push_back(move(tmp));
                dfs(dfs, i + 1, (ld | lb) << 1, (rd | lb) >> 1, v | lb);
                res.pop_back();
                left ^= lb;
            }
        };
        dfs(dfs, 0, 0, 0, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

 */

