/*
 * @lc app=leetcode.cn id=3310 lang=cpp
 * @lcpr version=30204
 *
 * [3310] 移除可疑的方法
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
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        vector<int> in(n), mark(n);
        for (auto& vec: invocations) {
            int a = vec[0], b = vec[1];
            ++in[b];
            g[a].push_back(b);
        }
        int delcnt = 0;
        int markcnt = 0;
        auto dfs = [&](auto&& dfs, int u)->void {
            mark[u] = 1;
            markcnt++;
            for (auto v: g[u]) {
                if (--in[v] == 0) ++delcnt;    
                if (!mark[v]) {
                    dfs(dfs, v);
                }

            }
        };
        if (in[k] == 0) ++delcnt;
        dfs(dfs, k);
        if (markcnt != delcnt) {
            vector<int> ans(n);
            for (int i = 0; i < n; i++) {
                ans[i] = i;
            }
            return ans;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!mark[i]) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n1\n[[1,2],[0,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n0\n[[1,2],[0,2],[0,1],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n[[1,2],[0,1],[2,0]]\n
// @lcpr case=end

 */

