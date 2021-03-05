/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
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
    bool isLongPressedName1(string name, string typed) {
        if (name.size() == 0 && typed.size() == 0) {
            return true;
        }
        if (name.size() == 0 || typed.size() == 0) {
            return false;
        }
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] != typed[j]) {
                return false;
            }
            ++i;
            char pre = typed[j];
            ++j;
            while (i < name.size() && j < typed.size() && name[i] != typed[j] && typed[j] == pre) {
                ++j;
            }
        }
        while (i == name.size() && j < typed.size() && typed[j] == name.back()) {
            ++j;
        }
        return i == name.size() && j == typed.size();
    }

    bool isLongPressedName2(string name, string typed) {
        int i = 0, j = 0;
        vector<int>  hash(26);
        while (i < name.size() && j < typed.size()) {
            char pre = name[i];
            int ct = 0;
            while (i < name.size() && name[i] == pre) {
                ++i;
                ++ct;
            }
            hash[pre - 'a'] = ct;
            ct = 0;
            while (j < typed.size() && typed[j] == pre) {
                ++j;
                ++ct;
            }
            if (hash[pre - 'a'] - ct > 0) {
                return false;
            }
            hash[pre - 'a'] = 0;
        }
        return i == name.size() && j == typed.size();
    }

    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] != typed[j]) {
                return false;
            }
            ++i;
            ++j;
            if (name[i] != name[i -1]) {
                while (j < typed.size() && typed[j] == name[i -1]) {
                    ++j;
                }
            }
        }
        return i == name.size() && j == typed.size();
    }
};
// @lc code=end

