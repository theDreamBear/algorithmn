/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30204
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        // 选哪个
        vector<vector<int>> ans;
        vector<int> tmp;
        auto dfs = [&](this auto&& dfs, int pos) {
            ans.push_back(tmp);
            if (pos >= nums.size()) {
                return;
            }
            for (int i = pos; i < nums.size(); i++) {
                if (i > pos and nums[i] == nums[i - 1]) continue;
                tmp.push_back(nums[i]);
                dfs(i + 1);
                tmp.pop_back();
            }
        };
        dfs(0);
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

