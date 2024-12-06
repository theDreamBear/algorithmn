/*
 * @lc app=leetcode.cn id=3001 lang=cpp
 * @lcpr version=30204
 *
 * [3001] 捕获黑皇后需要的最少移动次数
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
    int minMovesToCaptureTheQueen1(int a, int b, int c, int d, int e, int f) {
        // 最大为3
        // 1的情况
        // 象可以直接到达 中间没有隔着车
        // 车可以直接到达, 中间没有隔着象

        // 2的情况
        // 车不能直接到达, 车就可以走两步
        // 不用考虑后了
        // 可以直接到达但是中间隔着象, 需要先走动象
        
        // 所以只需要判断能不能1步到位就行了
        // 主对角线
        if (c - d == e - f) {
            if (a - b != c - d) {
                return 1;
            }
            // 在不在中间
            if (min(c, e) < a and a < max(c, e)) {
                return 2;
            }
            // 不在中间
            return 1;
        }
        // 反对角线
        if (c + d == e + f) {
            if (a + b != c + d) {
                return 1;
            }
            // 在不在中间
            if (min(c, e) < a and a < max(c, e)) {
                return 2;
            }
            // 不在中间
            return 1;
        }
        if (a == e) {
            if (c != a) {
                return 1;
            }
            if (min(b, f) < d and d < max(b, f)) {
                return 2;
            }
            return 1;
        }
        if (b == f) {
            if (b != d) {
                return 1;
            }
            if (min(a, e) < c and c < max(a, e)) {
                return 2;
            }
            return 1;
        }
        return 2;
    }

    int minMovesToCaptureTheQueen2(int a, int b, int c, int d, int e, int f) {
        // 最大为3
        // 1的情况
        // 象可以直接到达 中间没有隔着车
        // 车可以直接到达, 中间没有隔着象

        // 2的情况
        // 车不能直接到达, 车就可以走两步
        // 不用考虑后了
        // 可以直接到达但是中间隔着象, 需要先走动象
        
        // 所以只需要判断能不能1步到位就行了
        auto between=[&](int l, int m, int r) {
            return min(l, r) < m and m < max(l, r);
        };
        if (
                (c-d==e-f and (a-b!=c-d or !between(c,a,e))) or
                (c+d==e+f and (a+b!=c+d or !between(c,a,e))) or
                (a==e and (c!=a or !between(b, d, f))) or
                (b==f and (b!=d or !between(a, c,e)))
            ) return 1;
        return 2;
    }

    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        vector<vector<int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                int x = a + dir[i][0] * j;
                int y = b + dir[i][1] * j;
                if (x <= 0 or x > 8 or y <= 0 or y > 8) break;
                if (x == c and y == d) break;
                if (x == e and y == f) return 1;
            }
        }

        for (int i = 4; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                int x = c + dir[i][0] * j;
                int y = d + dir[i][1] * j;
                if (x <= 0 or x > 8 or y <= 0 or y > 8) break;
                if (x == a and y == b) break;
                if (x == e and y == f) return 1;
            }
        }
        return 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n8\n8\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n3\n3\n4\n5\n2\n
// @lcpr case=end

 */

