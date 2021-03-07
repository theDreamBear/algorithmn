/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
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

bool cmp(const string& left, const string& right) {
    int p1 = left.find_first_of(' ');
    int p2 = right.find_first_of(' ');
    bool l = isalpha(left[p1 + 1]);
    bool r = isalpha(right[p2 + 1]);
    if (l && r) {
        return pair<string, string>{left.substr(p1), left.substr(0, p1)} <
               pair<string, string>{right.substr(p2), right.substr(0, p2)};
    } else {
        return false;
    }
}

class Solution {
 public:
    pair<string, string> alphaSplit(string str) {
        int pos = str.find_first_of(' ');
        string label = str.substr(0, pos);
        return {string(str.c_str() + pos + 1), label};
    }

    bool isAlphaLog(const string& str) {
        return isalpha(str[str.find_first_of(' ') + 1]);
    }

    vector<string> reorderLogFiles1(vector<string>& logs) {
        vector<pair<string, string>> alpha_vec;
        vector<string> num_vec;
        vector<string> ans;

        for (auto& str : logs) {
            if (isAlphaLog(str)) {
                alpha_vec.push_back(alphaSplit(str));
            } else {
                num_vec.push_back(str);
            }
        }

        sort(alpha_vec.begin(), alpha_vec.end());
        for (auto& kv : alpha_vec) {
            ans.emplace_back(kv.second + " " + kv.first);
        }
        for (auto& str : num_vec) {
            ans.emplace_back(move(str));
        }
        return ans;
    }

    /*
        stable_sort  cmp 待比较的数字在前面， 如果 true 就交换
    */
    vector<string> reorderLogFiles2(vector<string>& logs) {
        stable_partition(logs.begin(), logs.end(), [](string& str) {
            return isalpha(str[str.find_first_of(' ') + 1]);
        });
        /*
            下面的cmp 写的有问题， 但是上面的stable_partition 掩盖了这个问题
        */
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }

    /*
        这个方法就是看起来简洁， 但是效率不如最开始的算法
    */
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(),
                    [&](const string& left, const string& right) {
                        int p1 = left.find_first_of(' ');
                        int p2 = right.find_first_of(' ');
                        bool l = isalpha(left[p1 + 1]);
                        bool r = isalpha(right[p2 + 1]);
                        if (l && r) {
                            return pair<string, string>{left.substr(p1),
                                                        left.substr(0, p1)} <
                                   pair<string, string>{right.substr(p2),
                                                        right.substr(0, p2)};
                        }
                        if (l) {
                            return true;
                        }
                        return false;
                    });
        return logs;
    }
};
// @lc code=end

int main() {
    vector<string> logs = {"dd1 1 2 3", "dd2 2 4 3"};
    Solution{}.reorderLogFiles(logs);
    for (auto& kv : logs) {
        cout << kv << endl;
    }
}
