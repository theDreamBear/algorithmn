/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30204
 *
 * [40] 组合总和 II
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 11 n!
        // 25 2^n
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> tmp;
        auto dfs = [&](auto&& dfs, int i, int left) {
            if (left == 0) {
                ans.push_back(tmp);
                return;
            }
            for (int j = i; j < candidates.size(); j++) {
                if (left < candidates[j]) break;
                if (j > i and candidates[j] == candidates[j - 1]) {
                    continue;
                }
                tmp.push_back(candidates[j]);
                dfs(dfs, j + 1, left - candidates[j]);
                tmp.pop_back();
            }
        };
        dfs(dfs, 0, target);
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

