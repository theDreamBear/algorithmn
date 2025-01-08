/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30114
 *
 * [90] 子集 II
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
            if (i > pos && nums[i] == nums[i - 1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            backtrack(ans, nums, tmp, i+ 1);
            tmp.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(ans, nums, tmp, 0);
        return ans;
    }

    // 选或者不选
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int>   tmp;
        auto dfs = [&](auto&& dfs, int i, int status, int v) {
            if (i >= nums.size()) {
                ans.push_back(tmp);
                return;
            }
            if (status == 0 or (v != nums[i])) {
                tmp.push_back(nums[i]);
                dfs(dfs, i + 1, 0, nums[i]);
                tmp.pop_back();
            }
            dfs(dfs, i + 1, 1, nums[i]);
        };
        //dfs(dfs, 0, 0, -1);
        // 优化下, 直接只使用v 表示上一个skip 的值
        auto dfs2 = [&](auto&& dfs2, int i, int v) {
            if (i >= nums.size()) {
                ans.push_back(tmp);
                return;
            }
            if (v != nums[i]) {
                tmp.push_back(nums[i]);
                dfs2(dfs2, i + 1, -100);
                tmp.pop_back();
            }
            dfs2(dfs2, i + 1, nums[i]);
        };
        dfs2(dfs2, 0, -100);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

