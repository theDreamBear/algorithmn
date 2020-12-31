/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
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
    string addStrings(string num1, string num2) {
        int len = (num1.size() > num2.size()) ? num1.size() + 2 : num2.size() + 2;
        char left[len];
        for (int i = 0; i < len; ++i) {
            left[i] = '0';
        }
        left[len - 1] = 0;
        int idx = len - 2;
        for (int i = num1.size() - 1; i >= 0; --i) {
            left[idx--] = num1[i];
        }
        char right[len];
        for (int i = 0; i < len; ++i) {
            right[i] = '0';
        }
        right[len - 1] = 0;
        idx = len - 2;
        for (int i = num2.size() - 1; i >= 0; --i) {
            right[idx--] = num2[i];
        }
        char ans[len];
        ans[len - 1] = 0;
        for (int i = len - 2; i >= 0; --i) {
            ans[i] = left[i] - '0' + right[i];
            if (ans[i] > '9') {
                ans[i] -= 10;
                ++left[i - 1];
            }
        }
        if (ans[0] == '0') {
            return ans + 1;
        }
        return ans;
    }
};
// @lc code=end

int main() { cout << Solution{}.addStrings("1", "9") << endl; }