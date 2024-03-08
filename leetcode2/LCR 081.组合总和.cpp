/*
 * @lc app=leetcode.cn id=LCR 081 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 081] 组合总和
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
    void backtrack(vector<vector<int>>& ans, vector<int> &tmp, int pos, int cur_sum, int target, vector<int>& candidates) {
        if (cur_sum == target) {
            ans.push_back(tmp);
            return;
        }
        if (pos >= candidates.size()) {
            return;
        }
        if (candidates[pos] + cur_sum <= target) {
            tmp.push_back(candidates[pos]);
            backtrack(ans, tmp, pos, candidates[pos] + cur_sum , target, candidates);
            tmp.pop_back();
            backtrack(ans, tmp, pos + 1,  cur_sum , target, candidates);
        }
    }

    void backtrack2(vector<vector<int>>& ans, vector<int> &tmp, int pos, int cur_sum, int target, vector<int>& candidates) {
        if (cur_sum == target) {
            ans.push_back(tmp);
            return;
        }
        if (pos >= candidates.size()) {
            return;
        }
        // 0个
        if (cur_sum + candidates[pos] <= target) {
            backtrack2(ans, tmp, pos + 1, cur_sum, target, candidates);
        }
        // 1～n 个
        for (int i = 0; i < (target - cur_sum) / candidates[pos]; i++) {
            tmp.push_back(candidates[pos]);
            backtrack2(ans, tmp, pos + 1, cur_sum + (i + 1) * candidates[pos] , target, candidates);
        }
        for (int i = 0; i < (target - cur_sum) / candidates[pos]; i++) {
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack2(ans, tmp, 0, 0, target, candidates);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1]\n2\n
// @lcpr case=end

 */

