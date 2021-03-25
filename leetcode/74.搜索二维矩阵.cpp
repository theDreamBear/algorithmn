/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
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
    bool match(vector<vector<int>>& matrix, int value, int target) {
        int x = value / matrix[0].size();
        int y = value % matrix[0].size();
        return matrix[x][y] == target;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (match(matrix, low, target)) {
            return true;
        }
        return match(matrix, high, target);
    }
};
// @lc code=end

int main() {
    vector<vector<int>> data {
        {1, 1},
    };
    cout << Solution{}.searchMatrix(data, 0);
}