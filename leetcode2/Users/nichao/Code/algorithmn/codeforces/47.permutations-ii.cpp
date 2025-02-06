/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30204
 *
 * [47] 全排列 II
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique1(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp(nums.size());
        // pick
        vector<int> mark(nums.size());
        const int offset = 10;
        auto dfs = [&](auto& dfs, int pos) {
            if (pos >= nums.size()) {
                ans.push_back(tmp);
                return;
            }
            vector<int> pick(30);
            for (int i = 0; i < nums.size(); i++) {
                if (mark[i] or pick[nums[i] + offset]) {
                    continue;
                }
                tmp[pos] = nums[i];
                pick[nums[i] + offset] = 1;
                mark[i] = 1;
                dfs(dfs, pos + 1);
                mark[i] = 0;
            }
        };
        dfs(dfs, 0);
        return ans;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> ans;
        vector<int> tmp(nums.size());
        // pick
        vector<int> mark(nums.size());
        const int offset = 10;
        auto dfs = [&](auto& dfs, int pos) {
            if (pos >= nums.size()) {
                ans.push_back(tmp);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (mark[i] or i > 0 and nums[i - 1] == nums[i] and !mark[i - 1]) {
                    continue;
                }
                tmp[pos] = nums[i];
                mark[i] = 1;
                dfs(dfs, pos + 1);
                mark[i] = 0;
            }
        };
        dfs(dfs, 0);
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

