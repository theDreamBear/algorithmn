/*
 * @lc app=leetcode.cn id=1941 lang=cpp
 *
 * [1941] 检查是否所有字符出现次数相同
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
    bool areOccurrencesEqual(string s) {
        vector<int> ah(26);
        for (auto c : s) {
            ++ah[c - 'a'];
        }
        int ct = 0;
        for (int i = 0; i < 26; i++) {
            if (ah[i] == 0) {
                continue;
            }
            if (ct == 0 || ct == ah[i]) {
                ct = ah[i];
                continue;
            }
            return false;
        }
        return true;
    }
};
// @lc code=end

