/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 * @lcpr version=30204
 *
 * [1238] 循环码排列
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // ttl
    vector<int> circularPermutation_ttl(int n, int start) {
        int uppper = (1 << n);
        vector<set<int>> g(uppper);
        for (int i = 0; i < uppper; i++) {
            int j = i;
            while (j) {
                // 得到最右1
                int sub = j & (-j);
                // 负
                g[i].insert(i ^ sub);
                // 正
                g[i ^ sub].insert(i);
                j ^= sub;
            }
        }
        vector<int> ans{start};
        vector<int> mark(uppper);
        auto dfs = [&](auto&& dfs, int i, int u) {
            if (i >= uppper) {
                return g[u].contains(start);
            }
            mark[u] = 1;
            for (auto& v: g[u]) {
                if (!mark[v]) {
                    ans.push_back(v);
                    if (dfs(dfs, i + 1, v)) {
                        return true;
                    }
                    ans.pop_back();
                }
            }
            mark[u] = 0;
            return false;
        };
        dfs(dfs, 1, start);
        return ans;
    }

    vector<int> circularPermutation(int n, int start) {
        int uppper = (1 << n);
        vector<int> ans{start};
        vector<int> mark(uppper);
        auto dfs = [&](auto&& dfs, int u) {
            if (ans.size() == uppper) {
                return true;
            }
            mark[u] = 1;
            for (int i = 0; i < n; i++) {
                auto val = u ^ (1 << i);
                if (mark[val]) {
                    continue;
                }
                ans.push_back(val);
                if (dfs(dfs, val)) {
                    return true;
                }
                ans.pop_back();
            }
            mark[u] = 0;
            return false;
        };
        dfs(dfs, start);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

 */

