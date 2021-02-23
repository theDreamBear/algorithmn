/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (75.68%)
 * Likes:    474
 * Dislikes: 0
 * Total Accepted:    61.5K
 * Total Submissions: 80.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 *
 * 说明：解集不能包含重复的子集。
 *
 * 示例:
 *
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */
#include <vector>
#include <queue>
using namespace std;  // NOLINT

// @lc code=start
class Solution {
public:  // NOLINT
    /**
     *  1. n叉树先序优先遍历
     *  2. pos树的下标
     *
     * **/
    void subsetsHelper(vector<vector<int>>& ans, vector<int> temp, const vector<int>& nums, int pos) {  // NOLINT
        // 先序添加
        ans.push_back(temp);
        if (pos >= nums.size()) {
            return;
        }
        for (int i = pos; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            subsetsHelper(ans, temp, nums, i + 1);
            temp.pop_back();
        }
    }



    vector<vector<int>> subsets_1(vector<int>& nums) {  // NOLINT
        vector<vector<int>> ans;
        vector<int> temp;
        subsetsHelper(ans, temp, nums, 0);
        return ans;
    }

    vector<vector<int>> subsets2(vector<int>& nums) {  // NOLINT
        vector<vector<int>> ans;
        ans.push_back({});
        for (int i = 0; i < nums.size(); ++i) {
            int sz = ans.size();
            for (int j = 0; j < sz; ++j) {
                auto x = ans[j];
                x.push_back(nums[i]);
                ans.push_back(x);
            }
        }
        return ans;
    }

    /**
     *
     * bfs
     *  0 个元素, 1个元素, 2 个元素 一层层向外扩张
     *
     *
    */
    vector<vector<int>> subsets(vector<int>& nums) {  // NOLINT
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({-1, {}});
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto pr = q.front();
                q.pop();
                ans.push_back(pr.second);
                for (int pos = pr.first + 1; pos < nums.size(); ++pos) {
                    vector<int> temp = pr.second;
                    temp.push_back(nums[pos]);
                    q.push({pos, temp});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

