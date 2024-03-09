/*
 * @lc app=leetcode.cn id=LCR 082 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 082] 组合总和 II
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
    void combinationSum2(vector<vector<int>> &ans, vector<int> &tmp, vector<int>& candidates, int pos, int cur_sum, int target) {
        if (cur_sum == target) {
            ans.push_back(tmp);
            return;
        }
        if (pos >= candidates.size()) {
            return;
        }
        vector<int> ct(51);
        for (int i = pos; i < candidates.size() and cur_sum + candidates[i] <= target; i++) {
            if (ct[candidates[i]]) {
                continue;
            }
            ct[candidates[i]] = 1;
            tmp.push_back(candidates[i]);
            combinationSum2(ans, tmp, candidates, i + 1, cur_sum + candidates[i], target);
            tmp.pop_back();
        }
    }

    void combinationSum2Helper(vector<vector<int>> &ans, vector<int> &tmp, vector<int>& candidates, int pos, int cur_sum, int target, int pre) {
        if ( pos >= candidates.size()) {
            if (cur_sum == target) {
                ans.push_back(tmp);
            }
            return;
        }
        // pre代表上一个选择的
        if (cur_sum + candidates[pos] <= target) {
            // 选择
            tmp.push_back(candidates[pos]);
            combinationSum2Helper(ans, tmp, candidates, pos + 1, cur_sum + candidates[pos], target, candidates[pos]);
            tmp.pop_back();
        }
        if (candidates[pos] != pre) {
            // 不选择
            combinationSum2Helper(ans, tmp, candidates, pos + 1, cur_sum, target, pre);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        //combinationSum2(ans, tmp, candidates, 0, 0, target);
        combinationSum2Helper(ans, tmp, candidates, 0, 0, target, -1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */

