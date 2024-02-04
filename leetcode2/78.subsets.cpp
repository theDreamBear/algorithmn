/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30114
 *
 * [78] 子集
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
    void backtrack(vector<vector<int>> &ans, vector<int>& nums, vector<int>& tmp, int pos) {
        if (pos > nums.size()) {
            return;
        }
        ans.push_back(tmp);
        for (int i = pos; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(ans, nums, tmp, i+ 1);
            tmp.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(ans, nums, tmp, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

