/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30122
 *
 * [39] 组合总和
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
    vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        function<void(int pos, int sum)> backtrack = [&](int pos, int sum) {
            if (sum == target) {
                ans.push_back(temp);
                return;
            }
            if (pos >= candidates.size()) {
                return;
            }
            if (sum + candidates[pos] > target) {
                return;
            }
            temp.push_back((candidates[pos]));
            backtrack(pos, sum + candidates[pos]);
            temp.pop_back();
            backtrack(pos + 1, sum);
        };
        backtrack(0, 0);
        return ans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        function<void(int pos, int sum)> backtrack = [&](int pos, int sum) {
            if (sum == target) {
                ans.push_back(temp);
                return;
            }
            if (pos >= candidates.size()) {
                return;
            }
            if (sum + candidates[pos] > target) {
                return;
            }
            for (int i = pos; i < candidates.size(); i++) {
                temp.push_back(candidates[i]);
                backtrack(i, sum + candidates[i]);
                temp.pop_back();
            }
        };
        backtrack(0, 0);
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

 */

