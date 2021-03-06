/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
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
    int minDeletionSize(vector<string>& strs) {
        int ct = 0;
        int sz = strs[0].size();
        for (int i = 0; i < sz; ++i) {
            char pre = '0';
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j][i] < pre) {
                    ++ct;
                    break;
                } else {
                    pre = strs[j][i];
                }
            }
        }
        return ct;
    }
};
// @lc code=end
