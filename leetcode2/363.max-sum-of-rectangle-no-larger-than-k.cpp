/*
 * @lc app=leetcode.cn id=363 lang=cpp
 * @lcpr version=30122
 *
 * [363] 矩形区域不超过 K 的最大数值和
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
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSumSubmatrix_bad(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                matrix[i][j] += matrix[i - 1][j]; 
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= k and matrix[i][j] > ans) {
                    ans = matrix[i][j];
                }
                for (int m = 0; m < j; m++) {
                    int sub = matrix[i][j] - matrix[i][m];
                    if (sub <= k and sub > ans) {
                        ans = sub;
                    }
                }
                for (int m = 0; m < i; m++) {
                    int sub = matrix[i][j] - matrix[m][j];
                    if (sub <= k and sub > ans) {
                        ans = sub;
                    }
                }
                if (ans == k) {
                    break;
                }
            }
        }
        return ans;
    }

    // n^3 * lgn
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j++) {
                set<int> pre;
                pre.insert(0);
                for (int q = 1; q <= n; q++) {
                    int v = sum[j][q] - sum[i - 1][q];
                    auto it = pre.lower_bound(v - k);
                    if (it != pre.end()) {
                        int cur = v -  *it;
                        ans = max(ans, cur);
                    }
                    pre.insert(v);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,1],[0,-2,3]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[2,2,-1]]\n3\n
// @lcpr case=end

 */

