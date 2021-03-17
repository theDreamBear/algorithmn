/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<vector>
#include<algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
    // 使用库的方法
    vector<vector<int>> permute_algorithm(vector<int>& nums) {
        vector<vector<int>> ans;
        // 排序是必要的
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        }  while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
    /*
    q1. 什么时候是结果
    a1. cur 到了最后一个数字

    q2. 什么时候存
    a1.
    */
    void permuteHelper(int cur, vector<int>& nums, vector<vector<int>>& result) {
        if (cur >= nums.size() - 1) {
            //
            result.push_back(nums);
            return;
        }
        //permuteHelper(cur + 1, nums, result);
        // 深度优先
        for (int swapIndex = cur; swapIndex < nums.size(); ++swapIndex) {
            swap(nums[swapIndex], nums[cur]);
            permuteHelper(cur + 1, nums, result);
            swap(nums[swapIndex], nums[cur]);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteHelper(0, nums, ans);
        return ans;
    }
};
// @lc code=end

