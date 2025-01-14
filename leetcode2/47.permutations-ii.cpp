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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        auto dfs = [&](auto&& dfs, int p) {
            if (p == nums.size()) {
                ans.push_back(nums);
                return;
            }
            int cnt[30]{};
            for (int i = p; i < nums.size(); i++) {
                if (i > p and cnt[nums[i] + 10]) {

                    
                    continue;
                }
                swap(nums[i], nums[p]);
                cnt[nums[i] + 10]++;
                dfs(dfs, p + 1);
                cnt[nums[i] + 10]--;
                swap(nums[i], nums[p]);
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

