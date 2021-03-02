/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>
#include <sstream>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> split(string str) {
        vector<string> ans;
        auto pos = strtok((char*)str.c_str(), " ");
        while (pos != NULL) {
            ans.push_back(pos);
            pos = strtok(NULL, " ");
        }
        return ans;
    }

    void shift(string& str) {
        char c = str[0];
        for (int i = 1; i < str.size(); ++i) {
            str[i - 1] = str[i];
        }
        str.back() = c;
    }

    string toGoatLatin1(string S) {
        auto words = split(S);
        string ans;
        vector<int> hash(300);
        hash['a'] = 1;
        hash['e'] = 1;
        hash['i'] = 1;
        hash['o'] = 1;
        hash['u'] = 1;
        hash['A'] = 1;
        hash['E'] = 1;
        hash['I'] = 1;
        hash['O'] = 1;
        hash['U'] = 1;

        for (int i = 0; i < words.size(); ++i) {
            string temp = words[i];
            if (!hash[temp[0]]) {
                shift(temp);
            }
            temp += "ma";
            temp += string(i + 1, 'a');
            if (ans.empty()) {
                ans += temp;
            } else {
                ans += " " + temp;
            }
        }
        return ans;
    }

     string toGoatLatin(string S) {
        stringstream ss(S);
        string ans;
        vector<int> hash(300);
        hash['a'] = 1;
        hash['e'] = 1;
        hash['i'] = 1;
        hash['o'] = 1;
        hash['u'] = 1;
        hash['A'] = 1;
        hash['E'] = 1;
        hash['I'] = 1;
        hash['O'] = 1;
        hash['U'] = 1;
        string temp;
        int i = 1;
        while(ss >> temp) {
            if (!hash[temp[0]]) {
                shift(temp);
            }
            temp += "ma";
            temp += string(i, 'a');
            if (ans.empty()) {
                ans += temp;
            } else {
                ans += " " + temp;
            }
            ++i;
        }
        return ans;
    }
};
// @lc code=end

