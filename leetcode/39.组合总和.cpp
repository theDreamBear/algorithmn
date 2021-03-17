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
    void dfs(int pos, const vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int sum) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(temp);
            return;
        }
        if (pos >= candidates.size()) {
            return;
        }
        // 当前小的没戏 后面更别想了
        if (target - sum < candidates[pos]) {
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            // 未使用回溯 temp 传的未值类型
            // int left = target - sum;
            // for (int j = 0; j <= left / candidates[i]; ++j) {
            //     dfs(i + 1, candidates, target, res, temp, sum);
            //     temp.push_back(candidates[i]);
            //     sum += candidates[i];
            // }
            
            //  使用回溯 temp 为引用类型
            temp.push_back(candidates[i]);
            sum += candidates[i];
            dfs(i, candidates, target, res, temp, sum);
            temp.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(0, candidates, target, res, temp, 0);
        return res;
    }
};
// @lc code=end

