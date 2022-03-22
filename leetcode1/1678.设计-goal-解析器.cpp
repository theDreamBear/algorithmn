/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
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
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                ans.push_back('G');
                continue;
            }
            if (command[i] == '(') {
                if (i + 1 < command.size()) {
                    if (command[i + 1] == 'a') {
                        ans.push_back('a');
                        ans.push_back('l');
                        i += 3;
                    } else if (command[i + 1] == ')') {
                        ans.push_back('o');
                        i++;
                    }
                } else {
                    throw logic_error("bad1");
                }
            } else {
                throw logic_error("bad");
            }
        }
        return ans;
    }
};
// @lc code=end

