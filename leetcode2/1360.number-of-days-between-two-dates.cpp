/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 * @lcpr version=30204
 *
 * [1360] 日期之间隔几天
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bits/stdc++.h>
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
const int days[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution {
  public:
    int isLeap(int year) {
        return year % 400 == 0 or year % 4 == 0 and year % 100 != 0;
    }

    int getYearDay(int year) {
        return isLeap(year) ? 366 : 365;
    }

    int passDay(int year, int month, int day) {
        int ans = day;
        for (int i = 1; i < month; i++) {
            ans += days[i];
            if (i == 2) {
                ans += isLeap(year);
            }
        }
        return ans;
    }

    tuple<int, int, int> parse(string date) {
        stringstream ss(date);
        string       s;
        int          year, month, day;
        getline(ss, s, '-'), year  = atoi(s.c_str());
        getline(ss, s, '-'), month = atoi(s.c_str());
        getline(ss, s, '-'), day   = atoi(s.c_str());
        return {year, month, day};
    }

    int daysBetweenDates1(string date1, string date2) {
        if (date1 > date2)
            swap(date1, date2);
        auto [y1, m1, d1] = parse(date1);
        auto [y2, m2, d2] = parse(date2);
        if (y1 == y2) {
            return passDay(y2, m2, d2) - passDay(y1, m1, d1);
        }
        int ans = passDay(y2, m2, d2) - passDay(y1, m1, d1) + getYearDay(y1);
        for (int i = y1 + 1; i < y2; i++) {
            ans += getYearDay(i);
        }
        return ans;
    }

    int daysBetweenDates(string date1, string date2) {
        if (date1 > date2) swap(date1, date2);
        tm dt1;
        istringstream(date1) >> get_time(&dt1, "%Y-%m-%d");
        tm dt2;
        istringstream(date2) >> get_time(&dt2, "%Y-%m-%d");
        time_t t1 = mktime(&dt1), t2 = mktime(&dt2);
        double diff = difftime(t2, t1);
        return diff / (60 * 60 * 24);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "2019-06-29"\n"2019-06-30"\n
// @lcpr case=end

// @lcpr case=start
// "2020-01-15"\n"2019-12-31"\n
// @lcpr case=end

 */
