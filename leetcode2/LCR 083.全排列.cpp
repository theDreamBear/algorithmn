/*
 * @lc app=leetcode.cn id=LCR 083 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 083] 全排列
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
    void permute(vector<vector<int>>& ans, vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            permute(ans, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }

    void permute(vector<vector<int>>& ans, const vector<int>& nums, vector<int>& tmp, vector<int>& used) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = 1;
            tmp.push_back(nums[i]);

            permute(ans, nums, tmp, used);

            tmp.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        #ifndef XX
        permute(ans, nums, 0);
        #else
        vector<int> used(nums.size());
        vector<int> tmp;
        permute(ans, nums, tmp, used);
        #endif
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

