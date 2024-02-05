/*
 * @lc app=leetcode.cn id=LCR 074 lang=cpp
 * @lcpr version=30115
 *
 * [LCR 074] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& lhs, const vector<int>& rhs) {
            if (lhs[0] == rhs[0]) {
               return lhs[1] < rhs[1];
           }
           return lhs[0] < rhs[0];
        });
        int s = intervals[0][0], e = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= e) {
                e = max(e, intervals[i][1]);
            } else {
                ans.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        ans.push_back({s, e});
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

