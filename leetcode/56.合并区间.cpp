/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int left = -1, right = -1;
        for(auto& vec : intervals) {
            if (left == -1) {
                left = vec[0];
                right = vec[1];
            } else {
                if (right >= vec[0]) {
                    right = max(right, vec[1]);
                } else {
                    ans.push_back({left, right});
                    left = vec[0];
                    right = vec[1];
                }
            }
        }
        if (left != -1) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
// @lc code=end

