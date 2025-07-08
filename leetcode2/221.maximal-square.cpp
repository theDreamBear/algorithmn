/*
 * @lc app=leetcode.cn id=221 lang=cpp
 * @lcpr version=30204
 *
 * [221] 最大正方形
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
class Solution1 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] + matrix[i][j] - '0' - sum[i][j];
                if (matrix[i][j] == '1') ans = 1;
            }
        }
        auto cal = [&](int i, int j, int k) {
            // (k - 1, k) 的矩形面积
            // 右下角 i, j - 1
            // 左上角 i - k + 1, j - k
            return sum[i + 1][j] - sum[i + 1][j - k + 1] - sum[i - k + 1][j] + sum[i - k + 1][j - k + 1] == k * (k - 1) and
                   sum[i][j + 1] - sum[i][j - k + 1] - sum[i - k + 1][j + 1] + sum[i - k + 1][j - k + 1] == k * (k - 1);
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '1') continue;
                for (int step = 1; step <= min(i, j) + 1; step++) {
                    if (!cal(i, j, step)) break;
                    else {
                        ans = max(ans, step);
                    }
                }
            }
        }
        return ans * ans;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] + matrix[i][j] - '0' - sum[i][j];
            }
        }
        auto cal = [&](int i, int j, int k) {
            // i, j
            // i - k + 1, j - k + 1
            return sum[i + 1][j + 1] - sum[i + 1][j - k + 1] - sum[i - k + 1][j + 1] + sum[i - k + 1][j - k + 1] == k * k;
        };
        auto binary = [&](int i, int j) {
            // 二分
            int low = 0, high = min(i, j) + 1;
            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                if (cal(i, j, mid)) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            if (cal(i, j, high)) return high;
            return low;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '1') continue;
                ans = max(ans, binary(i, j));
            }
        }
        return ans * ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0","1"],["1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

 */

