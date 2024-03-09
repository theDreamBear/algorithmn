/*
 * @lc app=leetcode.cn id=LCR 084 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 084] 全排列 II
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
class Solution {
public:
    void permuteUnique(vector<vector<int>> &ans, vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> ex;
        for (int i = pos; i < nums.size(); i++) {
            if (ex.count(nums[i])) {
                continue;
            }
            ex.insert(nums[i]);
            swap(nums[i], nums[pos]);
            permuteUnique(ans, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUnique(ans, nums, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

