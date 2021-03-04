/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while (i < j) {
            while (i < j && !isalpha(S[i])) {
                ++i;
            }
            while (i < j && !isalpha(S[j])) {
                --j;
            }
            if (i < j) {
                swap(S[i], S[j]);
            }
            ++i;
            --j;
        }
        return S;
    }
};
// @lc code=end

