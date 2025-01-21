/*
 * @lc app=leetcode.cn id=2218 lang=cpp
 * @lcpr version=30204
 *
 * [2218] 从栈中取出 K 个硬币的最大面值和
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxValueOfCoins1(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        // 前 i 个取 j的最大值
        vector<vector<int>> f(n, vector<int>(k + 1, -1));
        auto dfs = [&](auto&& dfs, int i, int j) {
            if (i >= piles.size()) {
                return 0;
            }
            auto& v = f[i][j];
            if (v != -1) return f[i][j];
            v = dfs(dfs, i + 1, j);
            int val = 0;
            for (int x = 1; x <= min(j, (int)piles[i].size()); x++) {
                val += piles[i][x - 1];
                v = max(v, dfs(dfs, i + 1, j - x) + val);
            }
            return v;
        };
        return dfs(dfs, 0, k);
    }

    int maxValueOfCoins2(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        // 前 i 个取 j的最大值
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        // i 逆序
        // j 顺序
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                f[i][j] = f[i + 1][j];
                int val = 0;
                for (int x = 1; x <= min(j, (int)piles[i].size()); x++) {
                    val += piles[i][x - 1];
                    f[i][j] = max(f[i][j], f[i + 1][j - x] + val);
                }
            }
        }
        return f[0][k];
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        // 前 i 个取 j的最大值
        vector<vector<int>> f(2, vector<int>(k + 1));
        // i 逆序
        // j 顺序
        int ft = 0, st = 1;
        for (int i = n - 1; i >= 0; i--) {
            fill(f[st].begin(), f[st].end(), 0);
            for (int j = 0; j <= k; j++) {
                f[st][j] = f[ft][j];
                int val = 0;
                for (int x = 1; x <= min(j, (int)piles[i].size()); x++) {
                    val += piles[i][x - 1];
                    f[st][j] = max(f[st][j], f[ft][j - x] + val);
                }
            }
            swap(st, ft);
        }
        return f[ft][k];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,100,3],[7,8,9]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]]\n7\n
// @lcpr case=end

 */

