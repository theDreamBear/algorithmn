/*
 * @lc app=leetcode.cn id=1366 lang=cpp
 *
 * [1366] 通过投票对团队排名
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution1 {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.size() == 1 || votes[0].size() == 1) {
            return votes[0];
        }
        int sz = votes[0].size();
        int total = votes.size();
        unordered_set<char> hs;
        vector<vector<int>> rank(26, vector<int>(26));
        for (auto &str : votes) {
            for (int i = 0; i < str.size(); i++) {
                if (hs.count(str[i]) == 0) {
                    hs.insert(str[i]);
                }
                ++rank[str[i] - 'A'][i];
            }
        }
        vector<string> keys;
        for (auto c : hs) {
            auto& vec = rank[c - 'A'];
            string key;
            for (int i = 0; i < vec.size(); i++) {
                key += (to_string(total - vec[i]) + "_");
            }
            key.push_back(c);
            keys.emplace_back(key);
        }
        sort(keys.begin(), keys.end());
        string ans;
        for (auto& str : keys) {
            ans.push_back(str.back());
        }
        return ans;
    }
};

class Solution {
public:
    string get_key(char c, vector<int>& vl) {
        string key;
        for (int i = 0; i < vl.size(); i++) {
            key += (to_string(vl[i]) + "_");
        }
        key.push_back(c);
        return key;
    }

    string rankTeams(vector<string>& votes) {
        if (votes.size() == 1 || votes[0].size() == 1) {
            return votes[0];
        }
        int sz = votes[0].size();
        int total = votes.size();
        unordered_map<char, vector<int>> hash;
        for (auto &str : votes) {
            for (int i = 0; i < str.size(); i++) {
                if (hash.count(str[i]) == 0) {
                    hash[str[i]] = vector<int>(26, total);
                }
                --hash[str[i]][i];
            }
        }
        string s = votes[0];
        unordered_map<char, string> ckey;
        for (auto c : s) {
            string key = get_key(c, hash[c]);
            ckey[c] = key;
        }
        sort(s.begin(), s.end(), [&](char last, char before) {
            string lkey, bkey;
            return ckey[last] < ckey[before];
        });
        return s;
    }
};

// @lc code=end

