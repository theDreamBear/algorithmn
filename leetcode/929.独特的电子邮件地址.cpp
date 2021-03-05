/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
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
    int numUniqueEmails1(vector<string>& emails) {
        unordered_set<string> domains;
        for (auto& str : emails) {
            string local;
            bool f = false;
            for (int i = 0; i < str.size(); ++i) {
                if (!f) {
                    if (iswalnum(str[i])){
                        local.push_back(str[i]);
                    } else {
                        if (str[i] == '+') {
                            f = true;
                        } else if (str[i] == '@') {
                            --i;
                            f = true;
                        }
                    }
                } else {
                    if (str[i] == '@') {
                        local += (str.c_str() + i);
                        break;
                    }
                }
            }
            if (domains.count(local) == 0) {
                domains.insert(local);
            }
        }
        return domains.size();
    }

    /*
        题干有问题, 测试用例里面有数字, 题干没说明
    */
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> domains;
        for (auto& str : emails) {
            int pos = str.find('@');
            string local = str.substr(0, pos);
            string domain = str.c_str() + pos;

            auto end = local.find('+');
            if (end != string::npos) {
                local = local.substr(0, end);
            }
            local += domain;
            if (domains.count(local) == 0) {
                domains.insert(local);
            }
        }
        return domains.size();
    }
};
// @lc code=end
