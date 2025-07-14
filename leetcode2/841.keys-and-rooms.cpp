/*
 * @lc app=leetcode.cn id=841 lang=cpp
 * @lcpr version=30204
 *
 * [841] 钥匙和房间
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
    bool canVisitAllRooms1(vector<vector<int>>& rooms) {
        // 图遍历
        // 看能不能访问到所有节点
        int n = rooms.size();
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        int ans = 0;
        vis[0] = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ans++;
            for (auto& v: rooms[node]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        };
        return ans == n;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // 图遍历
        // 看能不能访问到所有节点
        int n = rooms.size();
        vector<int> vis(n);
        int ans = 0;
        auto dfs = [&](auto&& dfs, int u)->void {
            ans++;
            vis[u] = 1;
            for (auto& v: rooms[u]) {
                if (!vis[v]) {
                    dfs(dfs, v);
                }
            }
        };
        dfs(dfs, 0);
        return ans == n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1],[2],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[3,0,1],[2],[0]]\n
// @lcpr case=end

 */

