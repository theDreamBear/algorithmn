/*
 * @lc app=leetcode.cn id=3044 lang=cpp
 * @lcpr version=30204
 *
 * [3044] 出现频率最高的质数
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
    // 看错题意了, 画蛇添足了
    int mostFrequentPrime(vector<vector<int>>& mat) {
        vector<vector<int>> dir{{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
        int m = mat.size();
        int n = mat[0].size();
        // int dp[m][n][8];
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         for (int k = 0; k < 8; k++) {
        //             dp[i][j][k] = 0;
        //         }
        //     }
        // }
        unordered_map<long long, int> freq;
        auto isPrime = [&](long long val)->bool {
            if (val == 1) return false;
            if (val == 2) return true;
            for (int i = 2; i * i <= val; i++) {
                if (val % i == 0) return false;
            }
            return true;
        };
        auto traversal = [&](int i, int j, int k) {
            long long res = 0;
            while (i >= 0 and i < m and j >= 0 and j < n) {
                //dp[i][j][k] = 1;
                res = res * 10 + mat[i][j];
                if (res > 10 and isPrime(res)) {
                    freq[res]++;
                }
                i = i + dir[k][0];
                j = j + dir[k][1];
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 边界
                //if (i == 0 or j == 0 or i == m - 1 or j == n - 1) {
                    for (int k = 0; k < 8; k++) {
                        traversal(i, j, k);
                    }
                //}
            }
        }
        int maxFre = 0;
        for (auto& [k, v]: freq) {
            maxFre = max(maxFre, v);
        }
        if (maxFre == 0) return -1;
        long long ans = 0;
        for (auto& [k, v]: freq) {
            if (v == maxFre and ans < k) {
                ans = k;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1],[9,9],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[7]]\n
// @lcpr case=end

// @lcpr case=start
// [[9,7,8],[4,6,5],[2,8,6]]\n
// @lcpr case=end

 */

