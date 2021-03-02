/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
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
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> splitToWords(string str) {
        vector<string> ans;
        /*
            先将所有非字母转为空格,
            使用 sstream 简化字符串分割, 很巧妙
        */
        for (auto& c : str) {
            if (!isalpha(c)) {
                c = ' ';
            } else if (c >= 'A' && c <= 'Z') {
                c ^= 0x20;
            }
        }
        stringstream ss(str);
        string temp;
        while (ss >> temp) {
            ans.emplace_back(temp);
        }
        return ans;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban_set;
        for (auto & str : banned) {
            ban_set.insert(str);
        }
        unordered_map<string, int> hash;
        auto vec = splitToWords(paragraph);
        for (auto& str : vec) {
            if (ban_set.count(str) == 0) {
                ++hash[str];
            }
        }
        int max_ct = 0;
        string ans;
        for (auto& kv : hash) {
            if (kv.second > max_ct) {
                ans = kv.first;
                max_ct = kv.second;
            }
        }
        return ans;
    }

    string mostCommonWord1(string paragraph, vector<string>& banned) {
        unordered_set<string> ban_set;
        for (auto & str : banned) {
            ban_set.insert(str);
        }
        unordered_map<string, int> hash;
        int pos = 0;
        while (pos < paragraph.size()) {
            //
            while(pos < paragraph.size() && !isalpha(paragraph[pos])) {
                ++pos;
            }
            int end = pos;
            while (end < paragraph.size() && isalpha(paragraph[end])) {
                ++end;
            }
            if (end != pos) {
                string temp = paragraph.substr(pos, end - pos);
                transform(temp.begin(), temp.end(), temp.begin(), [&](char& c) {
                    if (c >= 'A' && c <= 'Z') {
                        return c ^= 0x20;
                    }
                    return c;
                });
                if (ban_set.count(temp) == 0) {
                    ++hash[temp];
                }
            }
            pos = end;
        }
        string ans;
        int max_ct = 0;
        for (auto& kv : hash) {
            if (kv.second > max_ct) {
                ans = kv.first;
                max_ct = kv.second;
            }
        }
        return ans;
    }
};
// @lc code=end

