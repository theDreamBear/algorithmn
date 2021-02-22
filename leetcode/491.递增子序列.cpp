/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    /*
        去重麻烦, 有问题解法

    */
    void dfs(set<vector<int>>& ans, vector<int> temp, int pos,
             const vector<int>& nums) {
        // 边界
        if (pos >= nums.size()) {
            if (temp.size() > 1) {
                ans.insert(temp);
            }
            return;

       }
        dfs(ans, temp, pos + 1, nums);
        for (int k = pos; k < nums.size(); ++k) {
            if (temp.empty() || temp.back() <= nums[k]) {
                temp.push_back(nums[k]);
                dfs(ans, temp, k + 1, nums);
                temp.pop_back();
            }
        }
    }

    /*

    */
    void dfs_optimize(set<vector<int>>& ans, vector<int> temp, int pos,
             const vector<int>& nums) {
        // 提前剪枝
       // if (pos >= nums.size()) {
            if (temp.size() > 1) {
                ans.insert(temp);
            }
       //     return;
       //}
       // dfs(ans, temp, pos + 1, nums);
        for (int k = pos; k < nums.size(); ++k) {
            if (temp.empty() || temp.back() <= nums[k]) {
                temp.push_back(nums[k]);
                dfs(ans, temp, k + 1, nums);
                temp.pop_back();
            }
        }
    }


    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        dfs(ans, {}, 0, nums);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
// @lc code=end

int main() {
    vector<int> nums = {4, 6, 7, 7};
    Solution{}.findSubsequences(nums);
}
