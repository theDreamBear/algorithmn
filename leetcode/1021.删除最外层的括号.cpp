/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
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
    string removeOuterParentheses(string S) {
        string ans;
        int i = 0;
        while (i < S.size()) {
            int ct = 0;
            int j = i;
            do {
                if (S[i] == '(') {
                    ++ct;
                } else {
                    --ct;
                }
                ++i;
            } while (i < S.size() && ct != 0);
            string temp(S.begin() + j + 1, S.begin() + i - 1);
            ans += temp;
        }
        return ans;
    }
};
// @lc code=end

