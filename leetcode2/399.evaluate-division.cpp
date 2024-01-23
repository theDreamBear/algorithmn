/*
 * @lc app=leetcode.cn id=399 lang=cpp
 * @lcpr version=30113
 *
 * [399] 除法求值
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
     vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_map<string, int> keyToIdx;
        int maxIdx = 0;
        auto Alloc = [&](const string &key) {
            if (keyToIdx.count(key)) {
                return keyToIdx[key];
            }
            return keyToIdx[key] = maxIdx++;
        };
        auto contains = [&](const string &key) {
            return keyToIdx.count(key) > 0;
        };
        vector<vector<double>> grid(40, vector<double>(40, -1));
        for (int i = 0; i < equations.size(); i++) {
            int lhs = Alloc(equations[i][0]);
            int rhs = Alloc(equations[i][1]);
            double score = values[i];
            grid[lhs][rhs] = score;
            grid[rhs][lhs] = 1.0 / score;
        }
        for (int i = 0; i < maxIdx; i++) {
            grid[maxIdx][maxIdx] = 1;
        }
        auto bfs = [&](int start, int target) {
            queue<pair<int, double>> q;
            unordered_map<int, int> visited;
            q.push({start, 1});
            visited[start] = 1;
            while (!q.empty()) {
                int sz = 0;
                while (sz-- > 0) {
                    auto [p, score] = q.front();
                    q.pop();
                    for (int i = 0; i < maxIdx; i++) {
                        // 可达， 且未被访问
                        if (grid[p][i] != -1 && !visited.count(i)) {
                            double now = p * grid[p][i];
                            if (i == target) {
                                return now;
                            }
                            q.push({i, now});
                        }
                    }
                }
            }
            return -1.0;
        };
        vector<double> ans((queries.size()), -1.0);
        for (int i = 0; i < queries.size(); i++) {
            if (!contains(queries[i][0]) || !contains(queries[i][0])) {
                continue;
            }
            int lhs = Alloc(queries[i][0]);
            int rhs = Alloc(queries[i][1]);
            if (grid[lhs][rhs] != -1) {
                ans[i] = grid[lhs][rhs];
            }
            auto score = bfs(lhs, rhs);
            ans[i] = score;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["b","c"],["bc","cd"]]\n[1.5,2.5,5.0]\n[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"]]\n[0.5]\n[["a","b"],["b","a"],["a","c"],["x","y"]]\n
// @lcpr case=end

 */

