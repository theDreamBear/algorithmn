/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30114
 *
 * [46] 全排列
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
private:
    void dfs(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<int>& marked) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!marked[i]) {
                marked[i] = 1;
                temp.push_back(nums[i]);
                dfs(nums, ans, temp, marked);
                temp.pop_back();
                marked[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute1(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> marked(nums.size());
        vector<int> temp;
        dfs(nums, ans, temp, marked);
        return ans;
    }

    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        }
        while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, int pos) {
        if (pos >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            // 使用交换来代替marked，保证[pos, n) 的都是没有选择过的
            swap(nums[i], nums[pos]);
            dfs(nums, ans, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, ans, 0);
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

