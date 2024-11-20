/*
 * @lc app=leetcode.cn id=3243 lang=cpp
 * @lcpr version=30204
 *
 * [3243] 新增道路查询后的最短距离 I
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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        for (int i = 0; i + 1 < n; i++) {
            g[i].push_back(i + 1);
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < queries.size(); i++) {
            g[queries[i][0]].push_back(queries[i][1]);
            auto bfs = [&]() {
                vector<int> vis(n);
                queue<int> q;
                q.push(0);
                vis[0] = 1;
                int dis = 0;
                while (!q.empty()) {
                    dis++;
                    int sz = q.size();
                    while (sz--) {
                        auto v = q.front();
                        q.pop();
                        for (auto next: g[v]) {
                            if (!vis[next]) {
                                if (next == n - 1) return dis;
                                vis[next] = 1;
                                q.push(next);
                            }
                        }
                    }
                }
                return dis;
            };
            ans[i] = bfs();
        }
        return ans;
    }
};;
// @lc code=end



/*
// @lcpr case=start
// 5\n[[2, 4], [0, 2], [0, 4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0, 3], [0, 2]]\n
// @lcpr case=end

 */

