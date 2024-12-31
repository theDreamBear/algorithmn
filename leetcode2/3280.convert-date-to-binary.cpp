/*
 * @lc app=leetcode.cn id=3280 lang=cpp
 * @lcpr version=30204
 *
 * [3280] 将日期转换为二进制表示
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
    string convertDateToBinary(string date) {
        auto p = date.find("-");
        int year = atoi(date.substr(0, p).c_str());
        p++;
        date = date.substr(p);
        p = date.find("-");
        int month = atoi(date.substr(0, p).c_str());
        int day = atoi(date.substr(p + 1).c_str());
        auto toBinary = [](int val) {
            string res;
            while (val) {
                res.push_back((val & 1) + '0');
                val >>= 1;
            }
            ranges::reverse(res);
            return res;
        };
        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2080-02-29"\n
// @lcpr case=end

// @lcpr case=start
// "1900-01-01"\n
// @lcpr case=end

 */

