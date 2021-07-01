/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
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
    // bfs
    bool quick_fail(const unordered_set<string>& exitDead, string target) {
        bool all = true;
        for (int i = 0; i < 4; ++i) {
            char old = target[i];
            char forward = (target[i] - '0' + 1) % 10 + '0';
            char before = (target[i] - '0' + 9) % 10 + '0';
            target[i] = forward;
            if (!exitDead.count(target)) {
                all = false;
                break;
            }
            target[i] = before;
            if (!exitDead.count(target)) {
                all = false;
                break;
            }
            target[i] = old;
        }
        return all;
    }

    string roll(string str, int pos, int step) {
        char ch = (str[pos] - '0' + step + 10) % 10 + '0';
        str[pos] = ch;
        return str;
    }

    int bfs(unordered_set<string>& exitDead, string target) {
        int res = 0;
        queue<string> queue1;
        string source = "0000";
        queue1.push(source);
        exitDead.insert(source);
        while (!queue1.empty()) {
            int sz = queue1.size();
            ++res;
            for (int i = 0; i < sz; ++i) {
                auto str = queue1.front();
                queue1.pop();
                for (int j = 0; j < 4; ++j) {
                    auto forward = roll(str, j, 1);
                    if (forward == target) {
                        return res;
                    }
                    if (!exitDead.count(forward)) {
                        queue1.push(forward);
                        exitDead.insert(forward);
                    }
                    auto before = roll(str, j, -1);
                    if (!exitDead.count(before)) {
                        queue1.push(before);
                        exitDead.insert(before);
                    }
                    if (before == target) {
                        return res;
                    }
                }
            }
        }
        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> exitDead;
        for (auto& str : deadends) {
            exitDead.insert(str);
        }
        string source = "0000";
        if (source == target) {
            return 0;
        }
        if (exitDead.count(source) > 0 || quick_fail(exitDead, target)) {
            return -1;
        }

        return bfs(exitDead, target);
    }
};
// @lc code=end

