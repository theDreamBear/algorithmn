/*
 * @lc app=leetcode.cn id=2092 lang=cpp
 * @lcpr version=30204
 *
 * [2092] 找出知晓秘密的所有专家
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
    vector<int> findAllPeople_mle(int n, vector<vector<int>>& meetings, int firstPerson) {
        set<int> ans;
        ans.insert(0);
        ans.insert(firstPerson);
        ranges::sort(meetings, [&](auto& l, auto& r) {
            return l[2] < r[2];
        });
        int m = meetings.size();
        // 分组循环
        for (int i = 0; i < m; ) {
            int start = i++;
            while (i < m and meetings[i][2] == meetings[start][2]) i++;
            if (start + 1 == i) {
                if (ans.count(meetings[start][0]) or ans.count(meetings[start][1])) {
                    ans.insert(meetings[start][0]);
                    ans.insert(meetings[start][1]);
                }
                continue;
            }
            // [start, i - 1] 是时间相同的区间
            vector<vector<int>> g(n);
            set<int> ss;
            for (int j = start; j < i; j++) {
                int a = meetings[j][0], b = meetings[j][1];
                g[a].push_back(b);
                g[b].push_back(a);
                if (ans.count(a) or ans.count(b)) { 
                    ss.insert(a); ss.insert(b);
                }
            }
            queue<int> q;
            for (auto v: ss) {
                ans.insert(v);
                for (auto w: g[v]) {
                    // 这个位置有问题
                    ans.insert(w);
                    q.push(w);
                }
            }
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (auto v: g[u]) {
                    if (!ans.count(v)) {
                        ans.insert(v);
                        q.push(v);
                    }
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }

    vector<int> findAllPeople_bfs(int n, vector<vector<int>>& meetings, int firstPerson) {
        set<int> ans;
        ans.insert(0);
        ans.insert(firstPerson);
        ranges::sort(meetings, [&](auto& l, auto& r) {
            return l[2] < r[2];
        });
        int m = meetings.size();
        // 分组循环
        for (int i = 0; i < m; ) {
            int start = i++;
            while (i < m and meetings[i][2] == meetings[start][2]) i++;
            if (start + 1 == i) {
                if (ans.count(meetings[start][0]) or ans.count(meetings[start][1])) {
                    ans.insert(meetings[start][0]);
                    ans.insert(meetings[start][1]);
                }
                continue;
            }
            // [start, i - 1] 是时间相同的区间
            unordered_map<int, vector<int>> g;
            unordered_set<int> ss;
            for (int j = start; j < i; j++) {
                int a = meetings[j][0], b = meetings[j][1];
                g[a].push_back(b);
                g[b].push_back(a);
                if (ans.count(a) or ans.count(b)) { 
                    ss.insert(a); ss.insert(b);
                }
            }
            queue<int> q;
            for (auto v: ss) {
                ans.insert(v);
                // for (auto w: g[v]) {
                //     ans.insert(w);
                    q.push(v);
                //}
            }
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (auto v: g[u]) {
                    if (!ans.count(v)) {
                        ans.insert(v);
                        q.push(v);
                    }
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }

    vector<int> findAllPeople_dfs(int n, vector<vector<int>>& meetings, int firstPerson) {
        set<int> ans;
        ans.insert(0);
        ans.insert(firstPerson);
        ranges::sort(meetings, [&](auto& l, auto& r) {
            return l[2] < r[2];
        });
        int m = meetings.size();
        // 分组循环
        for (int i = 0; i < m; ) {
            int start = i++;
            while (i < m and meetings[i][2] == meetings[start][2]) i++;
            if (start + 1 == i) {
                if (ans.count(meetings[start][0]) or ans.count(meetings[start][1])) {
                    ans.insert(meetings[start][0]);
                    ans.insert(meetings[start][1]);
                }
                continue;
            }
            // [start, i - 1] 是时间相同的区间
            map<int, vector<int>> g;
            vector<int> hasSecret;
            map<int, int> vis;
            for (int j = start; j < i; j++) {
                int a = meetings[j][0], b = meetings[j][1];
                g[a].push_back(b);
                g[b].push_back(a);
                if (ans.count(a)) { 
                    hasSecret.push_back(a);
                }
                if (ans.count(b)) {
                    hasSecret.push_back(b);
                }
            }
            auto dfs = [&](auto&& dfs, int u)->void {
                vis[u] = 1;
                for (auto v: g[u]) {
                    if (!vis.count(v)) {
                        dfs(dfs, v);
                    }
                }
            };
            for (auto v: hasSecret) {
                if (!vis.count(v)) {
                    dfs(dfs, v);
                }
            }
            for (auto v: vis) {
                ans.insert(v.first);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // uf
        vector<int> fa(n);
        iota(fa.begin(), fa.end(), 0);

        auto find = [&](auto&& find, int x) {
            if (fa[x] == x) {
                return x;
            }
            return fa[x] = find(find, fa[x]);
        };

        auto merge = [&](int u, int v) {
            int pu = find(find, u);
            int pv = find(find, v);
            if (pu == pv) return;
            if (pu < pv) fa[pv] = pu;
            else {
                fa[pu] = pv;
            }
        };

        auto isloate = [&](int u) {
            if (fa[u] != u) {
                fa[u] = u;
            }
        };

        auto isConnected = [&](int u, int v)->bool {
            return find(find, u) == find(find, v);
        };

        merge(0, firstPerson);
        ranges::sort(meetings, [&](auto& l, auto& r) {
            return l[2] < r[2];
        });
        int m = meetings.size();
        // 分组循环
        for (int i = 0; i < m; ) {
            int start = i++;
            while (i < m and meetings[i][2] == meetings[start][2]) i++;
            for (int j = start; j < i; j++) {
                merge(meetings[j][0], meetings[j][1]);
            }
            for (int j = start; j < i; j++) {
                if (!isConnected(meetings[j][0], 0)) {
                    isloate(meetings[j][0]);
                    isloate(meetings[j][1]);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (isConnected(i, 0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[1,2,5],[2,3,8],[1,5,10]]\n1\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[3,1,3],[1,2,2],[0,3,3]]\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[3,4,2],[1,2,1],[2,3,1]]\n1\n
// @lcpr case=end

 */

