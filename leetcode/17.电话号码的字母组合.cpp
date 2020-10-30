/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
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
    map<int, string> num_alpha;

    void letterCombinationsHelper(vector<string>& temp, const string& digits) {
        int i = 0;
        if (i < digits.size() && temp.empty()) {
            string now = num_alpha[digits[i] - '0'];
            for (auto& c : now) {
                string s = string(1, c);
                temp.push_back(s);
            }
            ++i;
        }
        while (i < digits.size()) {
            string now = num_alpha[digits[i] - '0'];
            int sz = temp.size();
            for (int i = 0; i < sz; ++i) {
                for (int j = 0; j < now.size() - 1; ++j) {
                    string s = temp[i];
                    s.push_back(now[j]);
                    temp.push_back(s);
                }
                temp[i].push_back(now[now.size() - 1]);
            }
            ++i;
        }
    }

    vector<string> letterCombinations(string digits) {
        num_alpha[2] = "abc";
        num_alpha[3] = "def";
        num_alpha[4] = "ghi";
        num_alpha[5] = "jkl";
        num_alpha[6] = "mno";
        num_alpha[7] = "pqrs";
        num_alpha[8] = "tuv";
        num_alpha[9] = "wxyz";

        vector<string> result;
        letterCombinationsHelper(result, digits);
        return result;
    }
};
// @lc code=end
