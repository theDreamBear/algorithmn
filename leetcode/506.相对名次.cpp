/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
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
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans(nums.size());
        vector<pair<int, int>> vv;
        for (int i = 0; i < nums.size(); ++i) {
            vv.push_back({nums[i], i});
        }
        sort(vv.begin(), vv.end(), greater<pair<int, int>>());
        pair<int, int> g;
        if (vv.size() > 0) {
            g = vv[0];
            ans[g.second] = "Gold Medal";
        }
        if (vv.size() > 1) {
            g = vv[1];
            ans[g.second] = "Silver Medal";
        }
        if (vv.size() > 2) {
            g = vv[2];
            ans[g.second] = "Bronze Medal";
        }
        for (int i = 3; i < vv.size(); ++i) {
            g = vv[i];
            ans[g.second] = to_string(i + 1);
        }
        return ans;
    }
};
// @lc code=end
