/*
 * @lc app=leetcode.cn id=LCR 079 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 079] 子集
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
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& tmp, int pos) {
        ans.push_back(tmp);
        if (pos >= nums.size()) {
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(ans, nums, tmp, i + 1);
            tmp.pop_back();
        }
    }

    void backtrack2(vector<vector<int>>& ans, vector<int>& nums, vector<int>& tmp, int pos) {
        if (pos >= nums.size()) {
            ans.push_back(tmp);
            return;
        }
        backtrack(ans, nums, tmp, pos + 1);

        tmp.push_back(nums[pos]);
        backtrack(ans, nums, tmp, pos + 1);
        tmp.pop_back();
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int> tmp;
         backtrack2(ans, nums, tmp, 0);
         return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
         for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> tmp;
            int v = i;
            while (v) {
                int p = __builtin_ctz(v);
                tmp.push_back(nums[p]);
                v ^= (1 << p);
            }
            ans.push_back(tmp);
         }
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

