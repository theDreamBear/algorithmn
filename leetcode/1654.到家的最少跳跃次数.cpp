/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
constexpr int N = 15;
constexpr int base = 1 << N;

class Solution {
 public:
    /* 未通过
     *
     * */
    int minimumJumps_bad(vector<int> &forbidden, int a, int b, int x) {
        if (x == 0) {
            return 0;
        }
        unordered_set<int> forbidden_pos(forbidden.begin(), forbidden.end());
        queue<int> q;
        q.push(0);
        int ans = 0;
        int max_n = x + a * b;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto v = q.front();
                q.pop();
                int t = v >> 12;
                int actual = v & (base - 1);
                if (actual == x) {
                    return ans - 1;
                }
                forbidden_pos.insert(actual);
                // 往前
                int after = actual + a;
                if (after <= max_n && forbidden_pos.count(after) == 0) {
                    q.push(after);
                }
                // 往后
                if (t == 1) {
                    continue;
                }
                int b1 = actual - b;
                if (b1 >= 0) {
                    int v1 = (1 << 12) + b1;
                    q.push(v1);
                }
            }
        }
        return -1;
    }

    /* 从不成功到成功跨越的点
     * 1. 从取队列时 加入到 forbidden_pos  -> 入队列时  这样队列长度会小很多
     * 2. 最大长度改成 6001
     * 3. N 从 12 改到 15 (13也可以, 12小了)
     * 3. forbidden 的 0, 1 都要加入 forbidden_pos
     * */
    int minimumJumps_bad_fix(vector<int> &forbidden, int a, int b, int x) {
        if (x == 0) {
            return 0;
        }
        unordered_set<int> forbidden_pos;
        for (auto v : forbidden) {
            forbidden_pos.insert(v);
            forbidden_pos.insert(base + v);
        }
        queue<int> q;
        q.push(0);
        int ans = 0;
        int max_n = 6001;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto v = q.front();
                q.pop();
                int t = v >> N;
                int actual = v & (base - 1);
                if (actual == x) {
                    return ans - 1;
                }
                // 往前
                int after = actual + a;
                if (after <= max_n && forbidden_pos.count(after) == 0) {
                    forbidden_pos.insert(after);
                    q.push(after);
                }
                // 往后
                if (t == 1) {
                    continue;
                }
                int b1 = actual - b;
                if (b1 >= 0) {
                    int v1 = base + b1;
                    if (forbidden_pos.count(v1) == 0) {
                        forbidden_pos.insert(v1);
                        q.push(v1);
                    }
                }
            }
        }
        return -1;
    }


    /*  未通过
     *  小细节需要优化
     *  入队列时加入到 forb 更高效
     * */
    int minimumJumps_needfix(vector<int> &forbidden, int a, int b, int x) {
        if (x == 0) {
            return 0;
        }
        int max_n = 6001;
        vector<bool> forb(max_n);
        for (auto v : forbidden) {
            forb[v] = true;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        int ans = -1;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (node.first == x) {
                    return ans;
                }
                if (node.second == 0) {
                    forb[node.first] = true;
                }
                int f = node.first + a;
                if (f <= max_n && !forb[f]) {
                    q.push({f, 0});
                }
                if (node.second == 0) {
                    int be = node.first - b;
                    if (be >= 0 && !forb[be]) {
                        q.push({be, 1});
                    }
                }
            }
        }
        return -1;
    }

    /*  bfs
     *  优化点 1 入队列时加入到 forb
     * */
    int minimumJumps_bfs(vector<int> &forbidden, int a, int b, int x) {
        if (x == 0) {
            return 0;
        }
        // 数学知识优化
        int g = gcd(a, b);
        if (x % g != 0) {
            return -1;
        }
        int max_n = 6001;
        vector<bool> forb(max_n);
        for (auto v : forbidden) {
            forb[v] = true;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        forb[0] = true;
        int ans = -1;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (node.first == x) {
                    return ans;
                }
                int f = node.first + a;
                if (f <= max_n && !forb[f]) {
                    forb[f] = true;
                    q.push({f, 0});
                }
                if (node.second == 0) {
                    int be = node.first - b;
                    if (be >= 0 && !forb[be]) {
                        // 回退时不需要加入到 forb
                        // 避免前进到该位置时缺少回退能力
                        q.push({be, 1});
                    }
                }
            }
        }
        return -1;
    }


    int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
        if (x == 0) {
            return 0;
        }
        // 数学知识优化
        int g = gcd(a, b);
        if (x % g != 0) {
            return -1;
        }
        int max_n = 6001;
        vector<bool> forb(max_n);
        for (auto v : forbidden) {
            forb[v] = true;
        }
        forb[0] = true;
        int ans = -1;
        function<void(int, int, bool)> dfs = [&](int nums, int cnt, bool back) {
            if (ans == -1 && nums >= 0 && nums < max_n) {
                if (nums == x) {
                    ans = cnt;
                    return;
                }
                int after = nums + a;
                if (after < max_n && !forb[after]) {
                    forb[after] = true;
                    dfs(after, cnt + 1, false);
                }
                int be = nums - b;
                if (!back && be >= 0 && !forb[be]) {
                    dfs(be, cnt + 1, true);
                }
            }
        };
        dfs(0, 0, false);
        return ans;
    }
};

// @lc code=end

