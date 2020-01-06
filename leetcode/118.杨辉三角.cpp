/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (65.04%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    52.1K
 * Total Submissions: 79.9K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        auto ans = vector<vector<int>>{}; 
        if (numRows == 0) {
            return ans;
        }
        if (numRows == 1) {
            ans.push_back({1});
            return ans;
        }
        auto pri = vector<int>{1};
        ans.push_back(pri);
        for(int i = 2; i <= numRows; ++i) {
            auto now = vector<int>(i, 1);
            // 利用对称性
            int sz = (i - 1) / 2 + 1;
            for (int j = 1; j < sz; ++j) {
                now[j] = pri[j - 1] + pri[j];
                now[i - j - 1] = now[j];
            }
            ans.push_back(now);
            pri = now;
        }
        return ans;
    }
};
// @lc code=end

