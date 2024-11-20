/*
 * @lc app=leetcode.cn id=3240 lang=cpp
 * @lcpr version=30204
 *
 * [3240] 最少翻转次数使二进制矩阵回文 II
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
    int minFlips(vector<vector<int>>& grid) {
        int rcnt = 0, ccnt = 0;
        int rones = 0, cones = 0;
        int m  = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int l = 0, r = n - 1; l <= r; l++, r--) {
                rones += grid[i][l] + grid[i][r] - grid[i][l] * (l == r);
                if (grid[i][l] != grid[i][r]) {
                    rcnt++;
                }
            }
        }
        // fix;
        // rcnt 个翻转, rones个1
        //rones %= 4;
        for (int i = 0; i < n; i++) {
            for (int l = 0, r = m - 1; l <= r; l++, r--) {
                cones += grid[l][i] + grid[r][i] - grid[l][i] * (l == r);
                if (grid[l][i] != grid[r][i]) {
                    ccnt++;
                }
            }
        }
        //cones %= 4;
        auto fix = [](int m, int n, int cnt, int ones) {
            int left = ones % 4;
            // 直接翻转为0就行
            if (cnt >= left) {
                return cnt;
            }
            int lans = INT_MAX, rans = INT_MAX;
            // 1.翻转1->0
            if (n % 2 == 0) {
                int l = left;
                l -= cnt;
                if (l % 2 == 0) {
                    lans = cnt + l / 2;
                }
            } else {
                int l = left;
                l -= cnt;
                if (l % 2 == 1) {
                    if (l <= m) {
                        lans = cnt + l;
                    } else {
                        lans = cnt + m + (l - m) / 2;
                    }
                }
            }
            // 2. 反正0->1
            if (n % 2 == 0) {
                int r = 4 - left;

            }
        };
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[1]]\n
// @lcpr case=end

 */

