/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
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
    /*
        从左下角开始搜索
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                --i;
            } else {
                ++j;
            }
        }
        return false;
    }

    /*
        有点意思的二分
    */
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix[0].size() - 1;
        int top = 0,  bottom = matrix.size() - 1;
        function<bool(int, int, int, int)> dfs = [&](int l, int r, int t, int b) ->bool {
            if (l > r || t > b) {
                return false;
            }
            if (r - l >= b - t) {
                int cmid = (r - l) / 2 + l;
                int low = t, high = b;
                while (low <= high) {
                    int mid = (high - low) / 2 + low;
                    if (matrix[mid][cmid] == target) {
                        return true;
                    }
                    if (matrix[mid][cmid] < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return dfs(l, cmid - 1, low, b) || dfs(cmid + 1, r, t, low - 1);
            } else {
                int cmid = (b - t) / 2 + t;
                int low = l, high = r;
                while (low <= high) {
                    int mid = (high - low) / 2 + low;
                    if (matrix[cmid][mid] == target) {
                        return true;
                    }
                    if (matrix[cmid][mid] < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return dfs(l, low - 1, cmid + 1, b) || dfs(low, r, t, cmid - 1);
            }
        };
        return dfs(left, right, top, bottom);
    }
};
// @lc code=end

