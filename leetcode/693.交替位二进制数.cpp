/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
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

using namespace std;

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> bits(n);
        int start = 0, end = 31;
        while (end >= start) {
            if (bits[end] == 1) {
                break;
            }
            --end;
        }
        while (start < end) {
            if (bits[end - 1] == bits[end]) {
                return false;
            }
            --end;
        }
        return true;
    }
};
// @lc code=end

