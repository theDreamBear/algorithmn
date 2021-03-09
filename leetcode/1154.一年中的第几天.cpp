/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
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
    bool isLeapYear(int n) {
        return (n % 4 == 0 && n % 100 != 0) || ( n % 400 == 0);
    }

    int dayOfYear(string date) {
        auto pos = strtok((char*)date.c_str(), "-");
        int year = stoll(pos, NULL, 10);
        pos = strtok(NULL, "-");
        int month = stoll(pos, NULL, 10);
        pos = strtok(NULL, "-");
        int day = stoll(pos, NULL, 10);

        vector<int> day_of_month{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year)) {
            day_of_month[2]++;
        }

        for (int i = 1; i < month; ++i) {
            day_of_month[i] += day_of_month[i - 1];
        }
        return day + day_of_month[month - 1];
    }
};
// @lc code=end

