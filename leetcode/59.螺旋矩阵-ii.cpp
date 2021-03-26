/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cur = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        //
        // 1. = 写成了==
        // 2. 行列写反了
        for (; ;) {
            for (int i = left; i <= right; ++i) {
                ans[top][i] = cur++;
            }
            if (++top > bottom) {
                break;
            }
            for (int i = top; i <= bottom; ++i) {
                ans[i][right] = cur++;
            }
            if (--right < left) {
                break;
            }
            for (int i = right; i >= left; --i) {
                ans[bottom][i] = cur++;
            }
            if (--bottom < top) {
                break;
            }
            for (int i = bottom; i >= top; --i) {
                ans[i][left] = cur++;
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution{}.generateMatrix(3);
}
