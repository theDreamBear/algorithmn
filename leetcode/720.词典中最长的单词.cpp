/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
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
    /*
        通过空间换时间
    */
    string longestWord1(vector<string>& words) {
        set<string> hashset;
        for (auto& str : words) {
            hashset.insert(str);
        }
        int sz = 0;
        vector<string> ans;
        // 时间复杂度高的地方
        for (auto& str : words) {
            int i = 1;
            for (; i < str.size(); ++i) {
                string temp = str.substr(0, i);
                if (hashset.find(temp) == hashset.end()) {
                    break;
                }
            }
            // 找到每一个符合要求的
            if (i == str.size()) {
                ans.push_back(str);
            }
        }

        if (!ans.empty()) {
            int sz = 0;
            string s = "";
            for (auto& str : ans) {
                if (str.size() > sz) {
                    s = str;
                    sz = str.size();
                } else if (str.size() == sz && str < s) {
                    s = str;
                }
            }
            return s;
        }
        return "";
    }

    /*
        枚举
    */
    string longestWord2(vector<string>& words) {
        set<string> dict;
        queue<string> q;
        for (auto& str : words) {
            if (str.size() == 1) {
                q.push(str);
            }
            dict.insert(str);
        }
        string result = "";
        while (!q.empty()) {
            auto w = q.front();
            q.pop();
            if (w.size() > result.size() || w < result) {
                result = w;
            }
            w.push_back('0');
            // 枚举各种
            for (char c = 'a'; c <= 'z'; ++c) {
                w.back() = c;
                if (dict.count(w) > 0) {
                    q.push(w);
                    dict.erase(w);
                }
            }
        }
        return result;
    }

    /*
        trie树
    */

    struct Trie {
        vector<Trie> children;
        bool wordEnd;
    }
};
// @lc code=end
