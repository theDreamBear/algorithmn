/*
 * @lc app=leetcode.cn id=3047 lang=cpp
 * @lcpr version=30204
 *
 * [3047] 求交集区域内的最大正方形面积
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
    long long largestSquareArea1(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();
        auto cal = [&](auto&& cal, int i, int j)-> long long {
            long long a = bottomLeft[i][0], b = bottomLeft[i][1], c = topRight[i][0], d = topRight[i][1];
            long long a2 = bottomLeft[j][0], b2 = bottomLeft[j][1], c2 = topRight[j][0], d2 = topRight[j][1];
            if (a > a2) {
                return cal(cal, j, i);
            }
            if (b <= b2) {
                long long width = min({max(0ll, c - a2), max(0ll, d - b2), c2 - a2, d2 - b2, c - a, d - b});
                return width * width;
            } else {
                // (c, b) (a2, d2)
                long long width = min({max(0ll, c - a2), max(0ll, d2 - b), c2 - a2, d2 - b2, c - a, d - b});
                return width * width;
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ans = max(ans, cal(cal, i, j));
            }
        }
        return ans;
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            // 交集的左边界
            int L = max(bottomLeft[i][0], bottomLeft[j][0]);
            // 交集的右边界
            int R = min(topRight[i][0], topRight[j][0]);
            // 交集的下边界
            int D = max(bottomLeft[i][1], bottomLeft[j][1]);
            // 交集的上边界
            int U = min(topRight[i][1], topRight[j][1]);
            // 取交集长 / 宽的最小值
            long long t = min(R - L, U - D);
            if (t >= 0) ans = max(ans, t * t);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1],[2,2],[3,1]]\n[[3,3],[4,4],[6,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[1,2]]\n[[3,3],[4,4],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[3,3],[3,1]]\n[[2,2],[4,4],[4,2]]\n
// @lcpr case=end

 */

