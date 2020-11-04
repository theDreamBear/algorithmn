/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    void dfs(int pos, const vector<int>& candidates, int target, vector<vector<int>> res, vector<int> temp, int sum) {
        if (pos >= candidates.size()) {
            return;
        }
        if (sum == target) {
            res.push_back(temp);
            return;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

    }
};
// @lc code=end

