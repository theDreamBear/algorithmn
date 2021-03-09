/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
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
    /*
        是否为闰年
    */
    bool isLeapYear(int year) {
        if (year % 4 != 0) {
            return false;
        }
        return (year % 400 == 0) || (year % 100 != 0);
    }
    /*
        1971年 1 月 1 日星期五
        或者以今天为基准
        2021 3 9, 星期二
    */
    int getSequence(int year, int month, int day) {
        return year * 10000 + month * 100 + day;
    }

    vector<int> day_of_month{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<string> week_name{"Sunday",   "Monday", "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};

    int dayDistance(int year, int month, int day) {
        int cmpYear = 2021;
        int cmpMonth = 3;
        int cmpdDay = 9;

        int diff = 0;
        /*
            sign = -1 表示求的时间在已知时间之前
        */
        int sign = 1;
        if (getSequence(cmpYear, cmpMonth, cmpdDay) >
            getSequence(year, month, day)) {
            sign = -1;
            swap(cmpYear, year);
            swap(cmpMonth, month);
            swap(cmpdDay, day);
        }
        for (int i = cmpYear; i < year; ++i) {
            if (isLeapYear(i)) {
                diff += 366;
            } else {
                diff += 365;
            }
        }
        for (int i = 1; i < month; ++i) {
            if (i != 2) {
                diff += day_of_month[i];
            } else {
                diff += 28;
                if (isLeapYear(year)) {
                    ++diff;
                }
            }
        }
        diff += day;
        for (int i = 1; i < cmpMonth; ++i) {
            if (i != 2) {
                diff -= day_of_month[i];
            } else {
                diff -= 28;
                if (isLeapYear(cmpYear)) {
                    --diff;
                }
            }
        }
        diff -= cmpdDay;
        return sign * diff;
    }

    string dayOfTheWeek(int day, int month, int year) {
        int diff = dayDistance(year, month, day);
        // 这个 index 需要根据比较的那天来修正, 2021 3 9, 星期二 所以本次 index= 2
        int cmpIndex = 2;
        if (diff > 0) {
            diff = (diff + cmpIndex) % 7;
        } else {
            diff = (cmpIndex + diff + 7 * 10000) % 7;
        }
        return week_name[diff];
    }
};
// @lc code=end
