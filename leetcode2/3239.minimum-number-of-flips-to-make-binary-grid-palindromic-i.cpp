/*
 * @lc app=leetcode.cn id=3239 lang=cpp
 * @lcpr version=30204
 *
 * [3239] 最少翻转次数使二进制矩阵回文 I
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
    int minFlips1(vector<vector<int>>& grid) {
        int rcnt = 0, ccnt = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int l = 0, r = n - 1; l < r; l++, r--) {
                if (grid[i][l] != grid[i][r]) {
                    rcnt++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int l = 0, r = m - 1; l < r; l++, r--) {
                if (grid[l][i] != grid[r][i]) {
                    ccnt++;
                }
            }
        }
        return min(rcnt, ccnt);
    }

    int minFlips(vector<vector<int>>& grid) {
        int  rcnt = 0, ccnt = 0;
        int  m = grid.size(), n = grid[0].size();
        auto count_diff = [](int len1, int len2, auto&& get) -> int {
            int cnt = 0;
            for (int i = 0; i < len1; i++) {
                for (int l = 0, r = len2 - 1; l < r; l++, r--) {
                    if (get(i, l) != get(i, r))
                        cnt++;
                }
            }
            return cnt;
        };
        // 调用:
        return min(
            count_diff(m, n, [&](int i, int j) { return grid[i][j]; }),
            count_diff(n, m, [&](int i, int j) { return grid[j][i]; })
        );
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,0,0],[0,0,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[0]]\n
// @lcpr case=end

 */
