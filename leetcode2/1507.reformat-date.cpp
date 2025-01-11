/*
 * @lc app=leetcode.cn id=1507 lang=cpp
 * @lcpr version=30204
 *
 * [1507] 转变日期格式
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
    string reformatDate(string date) {
        string Mon[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        unordered_map<string, string> refM;
        for (int i = 1; i <= 12; i++) {
            string s;
            if (i < 10) {
                s = "0";
                s += (i + '0');
            } else {
                s = to_string(i);
            }
            refM[Mon[i]] = s;
        }
        stringstream ss(date);
        string d, m, y;
        ss >> d >> m >> y;
        d = d.substr(0, d.size() - 2);
        if (d.size() == 1) {
            d = "0" + d;
        }
        return y + "-" + refM[m] + "-" + d;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "20th Oct 2052"\n
// @lcpr case=end

// @lcpr case=start
// "6th Jun 1933"\n
// @lcpr case=end

// @lcpr case=start
// "26th May 1960"\n
// @lcpr case=end

 */

