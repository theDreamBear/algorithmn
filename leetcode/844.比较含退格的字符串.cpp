/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
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
    string getString(const string& str) {
        string ans;
        for (auto c : str) {
            if (c != '#') {
                ans.push_back(c);
            } else {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
    bool backspaceCompare1(string S, string T) {
        return getString(S) == getString(T);
    }

    void next(const string& str, int& i) {
        int ct = 0;
        while (i >= 0 && (ct > 0 || str[i] == '#')) {
            if (str[i] == '#') {
                ++ct;
                --i;
            } else {
                --ct;
                --i;
            }
        }
    }

    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        // 从后往前
        while (i >= 0 && j >= 0) {
            // S
            char left = 0, right = 0;
            next(S, i);
            if (i >= 0) {
                left = S[i];
            }
            // T
            next(T, j);
            if (j >= 0) {
                right = T[j];
            }
            if (left != right) {
                return false;
            }
            --i;
            --j;
        }

        // 收尾
        next(S, i);
        next(T, j);
        return i == j;
    }
};
// @lc code=end
