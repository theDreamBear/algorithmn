/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
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
    /*
        1. 字母
        2. 忽略大小写
    */
    string shortestCompletingWord1(string licensePlate, vector<string>& words) {
        unordered_map<char, int> hash;
        for (auto c : licensePlate) {
            if (isalpha(c)) {
                ++hash[tolower(c)];
            }
        }
        string ans;
        int max_len = INT_MAX;
        int rlen = hash.size();
        for (auto& word: words) {
            unordered_map<char, int> temp = hash;
            int len = rlen;
            for (auto c : word) {
                if (isalpha(c) && temp.count(tolower(c)) > 0) {
                    if (--temp[tolower(c)] == 0) {
                        --len;
                    }
                }
            }
            if (len == 0 && word.size() < max_len) {
                ans = word;
                max_len = ans.size();
            }
        }
        return ans;
    }

    vector<char> countWord(const string& str) {
        vector<char> ans(26,0);
        for (auto c : str) {
            if (isalpha(c)) {
                ++ans[tolower(c) - 'a'];
            }
        }
        return ans;
    }

    bool compare(const vector<char>& left, const vector<char>& right) {
        for (int i = 0; i < 26; ++i) {
            if (left[i] > right[i]) {
                return false;
            }
        }
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<char> source = countWord(licensePlate);
        string ans;
        for (auto& str : words) {
            if (compare(source, countWord(str)) && (ans == "" || str.size() < ans.size())) {
                ans = str;
            }
        }
        return ans;
    }
};
// @lc code=end

