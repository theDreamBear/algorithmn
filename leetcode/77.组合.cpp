/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (71.81%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    34.5K
 * Total Submissions: 47.4K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
#include <vector>
using namespace std;  // NOLINT

// @lc code=start
class Solution {
public:
    void combineHelper(vector<vector<int>>& result, vector<int>& temp, const int n, const int k, int pos) {  // NOLINT
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        for (int i = pos; i <= n; ++i) {
            temp.push_back(i);
            combineHelper(result, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        combineHelper(result, temp, n, k, 1);
        return result;
    }
};
// @lc code=end

