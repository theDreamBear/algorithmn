/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
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
    bool segmentValid(string& s) {
        if (s.size() == 1) {
            return true;
        }
        if (s[0] == '0') {
            return false;
        }
        if (s.size() == 2) {
            return true;
        }
        if (s.size() == 3) {
            return s <= "255";
        }
        return false;
    }

    void backtracking(vector<string>& res, const string& s, string& temp, int pos, int& left) {
        if (left == 0) {
            string r = s.substr(pos);
            if (!r.empty() && segmentValid(r)) {
                res.push_back(temp + r);
            }
            return;
        }
        string r;
        for (int i = pos; i < s.size() && i < pos + 3; ++i) {
            r.push_back(s[i]);
            if (segmentValid(r)) {
                r.push_back('.');
                temp += r;
                --left;
                backtracking(res, s, temp, i + 1, left);
                ++left;
                for (int k = 0; k <= i - pos + 1; ++k) {
                    temp.pop_back();
                }
                r.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp;
        int left = 3;
        backtracking(ans, s, temp, 0, left);
        return ans;
    }
};
// @lc code=end

int main() {
    auto ans = Solution{}.restoreIpAddresses("25525511135");
    for (auto str : ans) {
        cout << str << endl;
    }
}
