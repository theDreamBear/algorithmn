/*
 * @lc app=leetcode.cn id=435 lang=cpp
 * @lcpr version=30113
 *
 * [435] 无重叠区间
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
    /**
     * @brief: 本题的思路是贪心，每次选择结尾最小的区间，这样可以保留更多的区间
     *
     * @param intervals
     * @return int
     */
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // 🐷看清楚题目， 最小区间为负数
        int tail = INT_MIN;
        int ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int beg = intervals[i][0];
            int end = intervals[i][1];
            if (beg >= tail) {
               tail = end;
               continue;
            }
            tail = min(tail, end);
            ++ans;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [1,2], [1,2] ]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [2,3] ]\n
// @lcpr case=end

 */

