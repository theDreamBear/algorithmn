/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 * @lcpr version=30204
 *
 * [1185] 一周中的第几天
 * 
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string s = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
        tm t1;
        istringstream(s) >> get_time(&t1, "%Y-%m-%d");
        string wee[8] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return wee[t1.tm_wday];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 31\n8\n2019\n
// @lcpr case=end

// @lcpr case=start
// 18\n7\n1999\n
// @lcpr case=end

// @lcpr case=start
// 15\n8\n1993\n
// @lcpr case=end

 */

