/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */
#include <ranges.h>
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
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (A.size() == 0) {
            return true;
        }
        for (int i = 0; i < A.size(); ++i) {
            char temp = A[0];
            for (int j = 1; j < A.size(); ++j) {
                A[j - 1] = A[j];
            }
            A[A.size() - 1] = temp;
            if (A == B) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
