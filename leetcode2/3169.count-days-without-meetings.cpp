/*
 * @lc app=leetcode.cn id=3169 lang=cpp
 * @lcpr version=30204
 *
 * [3169] 无需开会的工作日
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
    int countDays1(int days, vector<vector<int>>& meetings) {
        ranges::sort(meetings);
        int left = days;
        int l = meetings[0][0], r = meetings[0][1];
        for (int i = 1; i < meetings.size(); i++) {
            if (r + 1 >= meetings[i][0]) {
                r = max(r, meetings[i][1]);
            } else {
                left -= (r - l + 1);
                l = meetings[i][0];
                r = meetings[i][1];
            }
        }
        return left - (r - l + 1);
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        ranges::sort(meetings);
        int left = days;
        int l = meetings[0][0], r = meetings[0][0];
        for (int i = 0; i < meetings.size(); i++) {
            if (r < meetings[i][0]) {
                left -= (r - l + 1);
                l = meetings[i][0];
            }
            r = max(r, meetings[i][1]);
        }
        return left - (r - l + 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n[[5,7],[1,3],[9,10]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[2,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[1,6]]\n
// @lcpr case=end

 */

