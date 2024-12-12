/*
 * @lc app=leetcode.cn id=2718 lang=cpp
 * @lcpr version=30204
 *
 * [2718] 查询后矩阵的和
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
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        unordered_set<int> vis[2];
        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0], idx = queries[i][1], val = queries[i][2];
            if (!vis[type].contains(idx)) {
                ans += (n - vis[type^1].size()) * val;
                vis[type].insert(idx);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,0,1],[1,2,2],[0,2,3],[1,0,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]\n
// @lcpr case=end

 */

