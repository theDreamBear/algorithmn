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
enum Status {
    init,
    prefix_space,
    prefix_sign,
    prefix_int,
    point,
    empty_point,
    mid_int,
    s_exp,
    suffix_sign,
    suffix_int,
    suffix_space,
    over,
};

enum CharType {
    char_number,
    char_exp,
    char_point,
    char_sign,
    char_space,
    char_over,
    char_bad,
};

unordered_map<Status, unordered_map<CharType, Status>> machine{
        {init,
         {
                 {char_space, prefix_space},
                 {char_sign, prefix_sign},
                 {char_number, prefix_int},
                 {char_point, empty_point}
         }
        },
        {prefix_space,
         {
                 {char_space, prefix_space},
                 {char_sign, prefix_sign},
                 {char_number, prefix_int},
                 {char_point, empty_point},
         }
        },
        {prefix_sign,
         {
                 {char_number, prefix_int},
                 {char_point, empty_point},
         }
        },
        {prefix_int,
         {
                {char_point, point},
                {char_exp, s_exp},
                {char_number, prefix_int},
                {char_space, suffix_space},
                {char_over, over},
         }
        },
        {point,
         {
                 {char_number,  mid_int},
                 {char_exp, s_exp},
                 {char_space, suffix_space},
                  {char_over, over},
         }
        },
        {empty_point,
         {
                 {char_number, mid_int},
         }
        },
        {mid_int,
         {
                 {char_number, mid_int},
                 {char_exp, s_exp},
                 {char_space, suffix_space},
                  {char_over, over},
         }
        },
        {s_exp,
         {
                 {char_sign, suffix_sign},
                 {char_number, suffix_int},
         }
        },
        {suffix_sign,
         {
                 {char_number, suffix_int},
         }
        },
        {suffix_int,
         {
                 {char_number, suffix_int},
                 {char_space, suffix_space},
                  {char_over, over},
         }
        },
        {suffix_space,
         {
                 {char_space, suffix_space},
                 {char_over, over},
         }
        },
};

CharType toCharType(char ch) {
    if (isdigit(ch)) {
        return char_number;
    }
    if (ch == 'e' || ch == 'E') {
        return char_exp;
    }
    if (ch == '.') {
        return char_point;
    }
    if (ch == '+' || ch == '-') {
        return char_sign;
    }
    if (ch == ' ') {
        return char_space;
    }
    return char_bad;
}


class Solution {
public:
    bool validNumber1(string s) {
        std::regex pattern(R"(^\s*[+-]?(\d+\.\d+|\.\d+|\d+\.|\d+)([eE][+-]?\d+)?\s*$)");
        std::regex p(R"(^\s*[+-]?(\d+|\d+\.\d+|\d+\.|\.\d+)([eE][+-]?\d+)?\s*$)");
        return regex_match(s, p);
    }

    bool validNumber2(string s) {
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

    // (\d+ \d+\. | \d+\.\d+ | \.\d+) ([eE][+-]?\d+)?

    /*
    \d+
    \d+\.
    \d+\.\d+
    or \.\d+
    */
    bool validNumber(string s) {
        Status st = init;
        for (int i = 0; i < s.size(); i++) {
            CharType t = toCharType(s[i]);
            if (char_bad == t) {
                return false;
            }
            if (!machine[st].count(t)) {
                return false;
            }
            st = machine[st][t];
        }
           if (!machine[st].count(char_over)) {
            return false;
        }
        return over == machine[st][char_over];
        //return st == prefix_int || st == point || st == mid_int || st == suffix_int || st == suffix_space;
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

