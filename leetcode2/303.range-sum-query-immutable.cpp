/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=30204
 *
 * [303] 区域和检索 - 数组不可变
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums): preSum(nums.size() + 1) {
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumArray", "sumRange", "sumRange", "sumRange"][[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]\n
// @lcpr case=end

 */

