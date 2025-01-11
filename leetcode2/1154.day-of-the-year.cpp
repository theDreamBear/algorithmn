/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 * @lcpr version=30204
 *
 * [1154] 一年中的第几天
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
    int dayOfYear(string date) {
        stringstream ss(date);
        string s;
        int year, month, day;
        if (getline(ss, s, '-')) {
            year = atoi(s.c_str());
        }
        if (getline(ss, s, '-')) {
            month = atoi(s.c_str());
        }
        if (getline(ss, s, '-')) {
            day = atoi(s.c_str());
        }
        auto isYeap = [&]() {
            return year % 400 == 0 or year % 4 == 0 and year % 100 != 0;
        };
        if (month == 1) return day;
        if (month == 2) return 31 + day;
        int ans = day;
        for (int i = 1; i < month; i++) {
            if (i == 1 || i == 3 || i == 5 || i== 7 || i == 8 || i == 10 || i == 12) {
                ans += 31;
            } else if (i == 2) {
                ans += 28;
                if (isYeap()) ans++;
            } else {
                ans += 30;
            }
        }
        return ans;
    }

    int dayOfYear(string date) {
        tm dt;
        istringstream(date) >> get_time(&dt, "%Y-%m-%d");
        return dt.tm_yday + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2019-01-09"\n
// @lcpr case=end

// @lcpr case=start
// "2019-02-10"\n
// @lcpr case=end

 */

