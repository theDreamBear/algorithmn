/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30116
 *
 * [70] 爬楼梯
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
using matrix = vector<vector<long long>>;

matrix operator* (matrix& a, matrix& b) {
    matrix c(a.size(), vector<long long>(a[0].size()));
    for (int k = 0; k < a[0].size(); k++) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                if (!a[i][k]) {
                    continue;
                }
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

matrix makeMatrix(int a, int b) {
    return matrix(a, vector<long long>(b));
}

matrix fastPow(matrix a, int n) {
    matrix c = makeMatrix(a.size(), a[0].size());
    for (int i = 0; i < a.size(); i++) c[i][i] = 1;
    while (n) {
        if (n & 1)  c = c * a;
        a = a * a;
        n >>= 1;
    }
    return c;
}

class Solution {
public:
    int climbStairs1(int n) {
        if (n == 1) {
            return 1;
        }
        int pp = 1, p = 1;
        while (--n > 0) {
            int tmp = p;
            p += pp;
            pp = tmp;
        }
        return p;
    }

    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        matrix a = {{1, 1}, {1, 0}};
        auto c = fastPow(a, n - 1);
        return c[0][0] + c[1][0];
    }

};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

