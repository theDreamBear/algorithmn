/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
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
    void inserRight(string& s, int pos, unordered_set<string>& exist,
                    vector<string>& ans) {
        int left = 0;
        int right = 0;
        for (int i = 0; i <= pos; ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
        }
        for (int j = pos + 1; j <= s.size(); ++j) {
            if (left - right == 1) {
                string temp = s;
                temp.insert(temp.begin() + j, ')');
                if (exist.find(temp) == exist.end()) {
                    exist.insert(temp);
                    ans.push_back(temp);
                }
            }
            if (s[j] == '(') {
                ++left;
            } else {
                ++right;
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        unordered_set<string> exist;
        vector<string> ans;
        if (n == 0) {
            return ans;
        }
        int i = 1;
        while (i <= n) {
            if (i != 1) {
                int sz = ans.size();
                vector<string> newCommer;
                for (int idx = 0; idx < sz; ++idx) {
                    string s = ans[idx];
                    for (int j = 0; j < s.size(); ++j) {
                        string news = s;
                        news.insert(news.begin() + j, '(');
                        inserRight(news, j, exist, newCommer);
                    }
                }
                ans = newCommer;
            } else {
                ans.emplace_back("()");
                exist.insert(move("()"));
            }
            ++i;
        }
        return ans;
    }
};
// @lc code=end

int main() {
    int n = 3;
    auto res = Solution{}.generateParenthesis(n);
    for (auto x : res) {
        cout << x << endl;
    }
}
