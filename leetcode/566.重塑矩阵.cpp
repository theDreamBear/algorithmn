/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
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

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) {
            return nums;
        }
        int row = nums.size();
        int col = nums[0].size();
        if (row * col != r * c) {
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int k = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int rr = k / col;
                int cc =  k % col;
                ans[i][j] = nums[rr][cc];
                ++k;
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> nums = {{1,2,3,4}};
    Solution{}.matrixReshape(nums, 2, 2);
}
