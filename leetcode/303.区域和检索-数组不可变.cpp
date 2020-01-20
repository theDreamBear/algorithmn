/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (58.65%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    26.2K
 * Total Submissions: 44.2K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * 示例：
 * 
 * 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组不可变。
 * 会多次调用 sumRange 方法。
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class NumArray {
public:
    int NumArray1(vector<int>& nums) {
        this->sum = nums;
        // 缓存 会超时
        vector<vector<int> > temp(nums.size(), vector<int>(nums.size()));
        for(int i = 0; i< nums.size(); ++i) {
            int ans = 0;
            for (int j = i; j < nums.size(); ++j) {
                ans += nums[j];
                temp[i][j] = ans;
            }
        }
        ans = temp;
        return 0;
    }

    /**
     *  sum[i] = sum[i - 1] + nums[i]
     *  ans(i, j) = sum[j] - sum[i - 1];
     * 
     * ***/
    NumArray(vector<int>& nums) {
        sum = vector<int>(nums.size());
        if (nums.size() != 0) {
            sum[0] = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                sum[i] = sum[i - 1] + nums[i];
            }
        }
    }
    
    int sumRange1(int i, int j) {
        //int ans = 0;
        //ans = accumulate(nums.begin() + i, nums.begin() + j + 1, ans);
        //return ans;
        return ans[i][j];
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sum[j];
        }
        return sum[j] - sum[i - 1];
    }
    private:
    vector<int> sum;
    vector<vector<int>> ans;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

