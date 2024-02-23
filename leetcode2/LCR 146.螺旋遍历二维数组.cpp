/*
 * @lc app=leetcode.cn id=LCR 146 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 146] 螺旋遍历二维数组
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
    vector<int> spiralArray1(vector<vector<int>>& array) {
        if (array.empty()) {
            return {};
        }
        int m = array.size();
        int n = array[0].size();
        if (n == 0) {
            return {};
        }
        vector<int> ans(m * n);
        int offset = 0;
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        int i = 0, j = 0;
        while (left <= right and top <= bottom) {
            // 右移
            if (j > right) {
                break;
            }
            while (j <= right) {
                ans[offset++] = array[i][j];
                if (j < right) {
                    j++;
                } else {
                    break;
                }
            }
            ++i;
            ++top;
            // 下移
            if (i > bottom) {
                break;
            }
            while (i <= bottom) {
                ans[offset++] = array[i][j];
                if (i < bottom) {
                    ++i;
                } else {
                    break;
                }
            }
            --j;
            --right;
            // 左移
            if (j < left) {
                break;
            }
            while (j >= left) {
                ans[offset++] = array[i][j];
                if (j > left) {
                    j--;
                } else {
                    break;
                }
            }
            --i;
            --bottom;
            // 上移
            if (i < top) {
                break;
            }
            while (i >= top) {
                ans[offset++] = array[i][j];
                if (i > top) {
                    i--;
                } else {
                    break;
                }
            }
            j++;
            ++left;
        }
        return ans;
    }

    vector<int> spiralArray(vector<vector<int>>& array) {
        if (array.empty()) {
            return {};
        }
        int m = array.size();
        int n = array[0].size();
        if (n == 0) {
            return {};
        }
        vector<int> ans(m * n);
        int offset = 0;
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        int i = 0, j = 0;
        while (offset < ans.size()) {
            for (int i = left; i <= right; i++) {
                ans[offset++] = array[top][i];
            }
            if (++top > bottom) {
                break;
            }
            for (int j = top; j <= bottom; j++) {
                ans[offset++] = array[j][right];
            }
            if (--right < left) {
                break;
            }
            for (int i = right; i >= left; i--) {
                ans[offset++] = array[bottom][i];
            }
            if (--bottom < top) {
                break;
            }
            for (int j = bottom; j >= top; j--) {
                ans[offset++] = array[j][left];
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[8,9,4],[7,6,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]\n
// @lcpr case=end

 */

