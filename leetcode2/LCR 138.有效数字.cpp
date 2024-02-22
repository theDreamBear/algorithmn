/*
 * @lc app=leetcode.cn id=LCR 138 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 138] 有效数字
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
#include<regex>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool validNumber1(string s) {
        std::regex pattern(R"(^\s*[+-]?(\d+\.\d+|\.\d+|\d+\.|\d+)([eE][+-]?\d+)?\s*$)");
        std::regex       p(R"(^\s*[+-]?(\d+|\d+\.\d+|\d+\.|\.\d+)([eE][+-]?\d+)?\s*$)");
        return regex_match(s, p);
    }

    bool validNumber(string s) {
        if (s.empty()) {
            return false;
        }
        int low = 0, high = s.size() - 1;
        // 去掉前面的空格
        while (low <= high and s[low] == ' ') {
            ++low;
        }
        // 去掉后面的空格
        while (low <= high and s[high] == ' ') {
            --high;
        }
        // 空字符串
        if (low > high) {
            return false;
        }
        if (s[low] == '+' or s[low] == '-') {
            if (++low > high) {
                return false;
            }
        }
        // (\d+ \d+\. | \d+\.\d+ | \.\d+) ([eE][+-]?\d+)?

        /*
        \d+
        \d+\.
        \d+\.\d+
        or \.\d+
        */
        if (!isdigit(s[low]) and s[low] != '.') {
            return false;
        }
        if (isdigit(s[low])) {
            while (low <= high and isdigit(s[low])) {
                low++;
            }
            // 整数
            if (low > high) {
                return true;
            }
            if (s[low] == '.') {
                low++;
                while (low <= high and isdigit(s[low])) {
                    low++;
                }
                // 小数
                if (low > high) {
                    return true;
                }
            }
        } else {
            if (++low > high) {
                return false;
            }
            if (!isdigit(s[low])) {
                return false;
            }
            while (low <= high and isdigit(s[low])) {
                low++;
            }
            if (low > high) {
                return true;
            }
        }
        if (s[low] != 'e' and s[low] != 'E') {
            return false;
        }
        if (++low > high) {
            return false;
        }
        if ((s[low] == '+' or s[low] == '-') and ++low > high) {
            return false;
        }
        while (low <= high and isdigit(s[low])) {
            low++;
        }
        return low > high;
    }
};
// @lc code=end

int main() {
    cout << Solution{}.validNumber("2e0");
}


/*
// @lcpr case=start
// "0"\n
// @lcpr case=end

// @lcpr case=start
// "e"\n
// @lcpr case=end

// @lcpr case=start
// "."\n
// @lcpr case=end

 */

