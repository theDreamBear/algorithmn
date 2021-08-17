/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    string removeKdigits_v(string s, int k) {
        if (k >= s.size()) {
            return "0";
        }
        bool flag = true;
        while (k && flag) {
            flag = false;
            // 发现效率低下的原因是上一个有效位没有保存
            for (int i = 0; i < s.size() - 1 && k; i++) {
                if (s[i] > s[i + 1]) {
                    s.erase(s.begin() + i);
                    k--;
                    flag = true;
                    break;
                }
            }
        }
        // 如果前面删除不够, 需要补充
        while (k > 0) {
            s.pop_back();
            k--;
        }
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            ++i;
        }
        if (i == s.size()) {
            return "0";
        }
        return s.substr(i);
    }

  string removeKdigits(string s, int k) {
    if (k >= s.size()) {
        return "0";
    }
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (res.empty() || res.back() <= s[i] || !k) {
            res.push_back(s[i]);
        } else {
            while (!res.empty() && res.back() > s[i] && k) {
                res.pop_back();
                --k;
            }
            res.push_back(s[i]);
        }
    }
    while (k > 0) {
        res.pop_back();
        k--;
    }
    const char* p = res.c_str();
    while (*p != '\0' && *p == '0') {
        ++p;
    }
    if (*p == '\0') {
        return "0";
    }
    return p;
}
};
// @lc code=end
