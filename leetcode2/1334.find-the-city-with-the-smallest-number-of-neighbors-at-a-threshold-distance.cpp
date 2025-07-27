/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 * @lcpr version=30204
 *
 * [1334] 阈值距离内邻居最少的城市
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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> f(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) {
            f[i][i] = 0;
        }
        for (auto& e: edges) {
            int u = e[0], v = e[1], c = e[2];
            f[u][v] = f[v][u] = c;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (f[i][k] + f[k][j] < f[i][j]) {
                        f[i][j] = f[i][k] + f[k][j];
                    }
                }
            }
        }
        int ans = 0, mx = INT_MAX;
        for (int i = 0; i < n; i++) {
            int ct = 0;
            for (int j = 0; j < n; j++) {
                if (f[i][j] <= distanceThreshold) ct++;
            }
            if (ct <= mx) {
                ans = i;
                mx = ct;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]\n2\n
// @lcpr case=end

 */

