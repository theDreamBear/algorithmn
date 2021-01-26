/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
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
    bool judgeCircle(string moves) {
        int ct_r = 0;
        int ct_u = 0;
        for (auto c : moves) {
            if (c == 'U') {
                ++ct_r;
            } else if (c == 'D') {
                --ct_r;
            } else if (c == 'R') {
                ++ct_u;
            } else {
                --ct_u;
            }
        }
        return ct_r == 0 && ct_u == 0;
    }
};
// @lc code=end
