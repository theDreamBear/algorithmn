/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 * @lcpr version=30204
 *
 * [1462] 课程表 IV
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
    vector<bool> checkIfPrerequisite1(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> G(numCourses);
        vector<bitset<200>> bs(numCourses);
        for (auto& vec: prerequisites) {
            int from = vec[0], to = vec[1];
            G[from].push_back(to);
        }
        vector<int> vis(numCourses);
        int n = queries.size();
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (!vis[u]) {
                // 记忆化搜索
                auto dfs = [&](auto&&dfs, int s)->bitset<200> {
                    if (vis[s]) {
                        return bs[s];
                    }
                    vis[s] = 1;
                    bitset<200> res;
                    res.set(s);
                    for (auto adj: G[s]) {
                        res |= dfs(dfs, adj);
                    }
                    return bs[s] = res;
                };
                dfs(dfs, u);
            }
            ans[i] = bs[u].test(v);
        }
        return ans;
    } 

    vector<bool> checkIfPrerequisite_floyd(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bitset<101>> bs(numCourses);
        for (auto& vec: prerequisites) {
            bs[vec[0]][vec[1]] = 1;
        }
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                if (bs[i][k]) {
                    bs[i] |= bs[k];
                }
            }
        }
        int n = queries.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = bs[queries[i][0]][queries[i][1]];
        }
        return ans;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> g(n), isPre(n, vector<int>(n));
        vector<int> indegree(n);
        for (auto& vec: pre) {
            g[vec[0]].push_back(vec[1]);
            indegree[vec[1]]++;
        }
        queue<int> pq;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                pq.push(i);
            }
        }
        while (!pq.empty()) {
            int u = pq.front(); pq.pop();
            for (auto& nei: g[u]) {
                isPre[u][nei] = 1;
                // 所有能达到u的都是前置
                for (int i = 0; i < n; i++) {
                    isPre[i][nei] |= isPre[i][u];
                }
                if (--indegree[nei] == 0) {
                    pq.push(nei);
                }
            }
        }
        vector<bool> res;
        for (auto& que: q) {
            res.push_back(isPre[que[0]][que[1]]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n[[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[]\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,2],[1,0],[2,0]]\n[[1,0],[1,2]]\n
// @lcpr case=end

 */

