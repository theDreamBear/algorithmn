/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
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
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        if (cpdomains.empty()) {
            return ans;
        }
        unordered_map<string, int> hash;
        for (auto& str : cpdomains) {
            int pos = str.find(" ");
            int times = stol(str.substr(0, pos), NULL, 10);
            while (pos != string::npos) {
                ++pos;
                hash[str.c_str() + pos] += times;
                pos = str.find(".", pos);
            }
        }

        for (auto& kv : hash) {
            string temp = to_string(kv.second) + " " + kv.first;
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

