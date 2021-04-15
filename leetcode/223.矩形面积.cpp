/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int recTangleArea(int x0, int y0, int x1, int y1) {
        if (x0 >= x1 || y0 >= y1) {
            return 0;
        }
        return (x1 - x0) * (y1 - y0);
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = recTangleArea(A, B, C, D);
        int area2 = recTangleArea(E, F, G, H);
        int commonArea = recTangleArea(max(A, E), max(B, F), min(C, G), min(D, H));
        return area1 + area2 - commonArea;
    }
};
// @lc code=end

