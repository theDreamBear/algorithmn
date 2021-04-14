/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    void backtracking(vector<vector<int>>& ans, vector<int>& temp, int v, int k,
                      int n, int sum) {
        if (temp.size() > k) {
            return;
        }
        if (temp.size() == k) {
            if (sum == n) {
                ans.push_back(temp);
            }
            return;
        }
        for (int i = v; i <= 9; ++i) {
            temp.push_back(i);
            backtracking(ans, temp, i + 1, k, n, sum + i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtracking(ans, temp, 1, k, n, 0);
        return ans;
    }
};
// @lc code=end
