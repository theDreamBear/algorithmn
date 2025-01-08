/*
 * @lc app=leetcode.cn id=面试题 08.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.01] 三步问题
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
const int mod = 1e9 + 7;
class Solution {
public:
    int waysToStep1(int n) {
        if (n <= 2) {
            return n;
        }
        int mod = 1e9 + 7;
        long long f2 = 1, f1 = 1, f0 = 2;
        for (int i = 3; i <= n; i++) {
            auto t = (f2 + f1 + f0) % mod;
            f2 = f1;
            f1 = f0;
            f0 = t;

        }
        return f0;
    }

    using matrix = vector<vector<long long>>;

    matrix matrixMul(matrix& a, matrix& b) {
        int m = a.size(), n = b[0].size();
        matrix ans(m, vector<long long>(n));
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < b.size(); k++) {
                for (int j = 0; j < n; j++) {
                    ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return ans;
    }

    matrix fastMi(matrix& base, matrix& a, int exp) {
        auto ans = base;
        while (exp) {
            if (exp & 1) ans = matrixMul(ans, a);
            exp >>= 1;
            a = matrixMul(a, a);
        }
        return ans;
    }

    int waysToStep(int n) {
        if (n <= 2) {
            return n;
        }
        matrix a{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
        matrix base{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        matrix f0{{2}, {1}, {1}};
        auto res = fastMi(base, a, n - 2);
        res = matrixMul(res, f0);
        return res[0][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

