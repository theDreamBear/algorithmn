/*
 * @lc app=leetcode.cn id=2685 lang=cpp
 * @lcpr version=30204
 *
 * [2685] 统计完全连通分量的数量
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
    int countCompleteComponents_1(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& v: edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<int> vis(n), tmp;
        auto dfs = [&](auto&& dfs, int u)->void {
            tmp.push_back(u);
            vis[u] = 1;
            for (auto& v: g[u]) {
                if (!vis[v]) dfs(dfs, v);
            }
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            tmp.clear();
            if (!vis[i]) {
                dfs(dfs, i);
                if (!tmp.empty()) {
                    int sz = tmp.size() - 1;
                    bool ok = true;
                    for (auto v: tmp) {
                        if (g[v].size() != sz) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& v: edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<int> vis(n);
        int cnt = 0, vnt = 0;
        auto dfs = [&](auto&& dfs, int u)->void {
            vis[u] = 1;
            cnt += g[u].size();
            vnt++;
            for (auto& v: g[u]) {
                if (!vis[v]) dfs(dfs, v);
            }
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vnt = 0;
            cnt = 0;
            if (!vis[i]) {
                dfs(dfs, i);
                if (cnt == vnt * (vnt - 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[0,2],[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[1,2],[3,4],[3,5]]\n
// @lcpr case=end

 */

