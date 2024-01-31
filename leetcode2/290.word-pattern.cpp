/*
 * @lc app=leetcode.cn id=290 lang=cpp
 * @lcpr version=30114
 *
 * [290] 单词规律
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<string> split(string s) {
        vector<string> res;
        const char* p = strtok((char*)s.c_str(), " ");
        res.push_back(p);
        while ((p = strtok(NULL, " "))) {
            res.push_back(p);
        }
        return res;
    }

    vector<string> split2(string s) {
        vector<string> res;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            res.push_back(tmp);
        }
        return res;
    }

    vector<string> split3(string s) {
        vector<string> res;
        auto start = s.find_first_not_of(" ", 0);
        auto pos = s.find_first_of(" ", start);
        while (string::npos != start) {
            res.push_back(s.substr(start, pos - start));
            start = s.find_first_not_of(" ", pos);
            pos = s.find_first_of(" ", start);
        }
        return res;
    }

    bool wordPattern1(string pattern, string s) {
        auto vec = split(s);
        if (pattern.size() != vec.size()) {
            return false;
        }
        unordered_map<char, string> hs;
        unordered_map<string, char> rhs;
        for (int i = 0; i < pattern.size(); i++) {
            if (hs.count(pattern[i]) == 0 && rhs.count(vec[i]) == 0) {
                hs[pattern[i]] = vec[i];
                rhs[vec[i]] = pattern[i];
                continue;
            }
            if (hs[pattern[i]] != vec[i] || rhs[vec[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }

    bool wordPattern(string pattern, string s) {
        auto vec = split3(s);
        if (pattern.size() != vec.size()) {
            return false;
        }
        string hs[26]; // 这个映射
        unordered_map<string, char> rhs;
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            if (hs[ch - 'a'] == "" && rhs.count(vec[i]) == 0) {
                hs[ch - 'a'] = vec[i];
                rhs[vec[i]] = pattern[i];
                continue;
            }
            if (hs[ch - 'a'] != vec[i] || rhs[vec[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abba"\n"dog cat cat dog"\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n"dog cat cat fish"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"dog cat cat dog"\n
// @lcpr case=end

 */

