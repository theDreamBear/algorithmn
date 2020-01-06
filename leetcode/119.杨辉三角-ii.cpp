/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (59.15%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 57.1K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow1(int rowIndex) {
        auto ans = vector<int>(rowIndex);
        if (rowIndex == 0) {
            ans.push_back({1});
            return ans;
        }
        auto pri = vector<int>{1};
        for(int i = 1; i <= rowIndex; ++i) {
            auto now = vector<int>(i + 1, 1);
            // 利用对称性
            int sz = (i) / 2 + 1;
            for (int j = 1; j < sz; ++j) {
                now[j] = pri[j - 1] + pri[j];
                now[i - j] = now[j];
            }
            pri = now;
        }
        return pri;;
    }

    vector<int> getRow(int rowIndex) {
        auto ans = vector<int>(rowIndex + 1, 1);
        if (rowIndex == 0) {
            return ans;
        }
        auto pri = vector<int>(rowIndex + 1, 1);
        int sz = rowIndex / 2 + 1; 
        for (int i = 1; i < sz; ++i) {
            // 这地方考虑 整数不能整除,所以只能先乘再除, 这是会带来个问题 结果可能越界,
            pri[i] = ((long long)pri[i - 1] * (rowIndex - i + 1) / i);
            pri[rowIndex - i] = pri[i];
        }
        return pri;
    }
};
// @lc code=end

