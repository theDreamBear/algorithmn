/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
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
    int toDes(const string& s) {
        int zeroFirst = 0;
        int oneFirst = 0;
        for (int i = 0; i < s.size(); i++) {
#ifdef VI
            if (s[i] == '0') {
                if (i % 2 == 0) {
                    ++oneFirst;
                } else {
                    ++zeroFirst;
                }
            } else {
                if (i % 2 == 0) {
                    ++zeroFirst;
                } else {
                    ++oneFirst;
                }
            }
#else
            if ((s[i] - '0') ^ (!(i & 0x1))) {
                zeroFirst++;
            } else {
                oneFirst++;
            }
        }
#endif
        return min(zeroFirst, oneFirst);
    }

    int minOperations(string s) {
        return toDes(s);
    }
};
// @lc code=end

