/*
 * @lc app=leetcode.cn id=966 lang=cpp
 *
 * [966] 元音拼写检查器
 */
#include <string.h>
#include <sys/time.h>

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
    void stringToLower(string& str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    

    void string2foolString(string& str) {
        transform(str.begin(), str.end(), str.begin(), [&](char c){
            if (isVowel(c)) {
                return '-';
            } else {
                return c;
            }
        });
    }

    /*
        犯的错，completeMatch 没有穿引用， 造成超时 
    */
    bool completeMatch(const unordered_set<string>& wordSet, const string& queryWord) {
        if (wordSet.find(queryWord) != wordSet.end()) {
            return true;
        }
        return false;
    }

    bool ignoreCaseMatch(const unordered_map<string, string>& wordMap, string queryWord) {
        return wordMap.find(queryWord) != wordMap.end();
    }

    bool vowelMatch(const unordered_map<string, string>& wordMap, string queryWord) {
        return wordMap.find(queryWord) != wordMap.end();
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> wordSet;
        for (auto& str : wordlist) {
            wordSet.insert(str);
        }

        unordered_map<string, string> lower2Origin;
        unordered_map<string, string> vowel2Origin;
        for (int i = int(wordlist.size()) - 1; i >= 0; --i) {
            string temp = wordlist[i];
            stringToLower(temp);
            lower2Origin[temp] = wordlist[i];

            string2foolString(temp);
            vowel2Origin[temp] = wordlist[i];
        }

        vector<string> ans(queries.size(), "");
        for (int i = 0; i < queries.size(); ++i) {
            if (wordSet.find(queries[i]) != wordSet.end()) {
                ans[i] = queries[i];
                continue;
            } 
            string temp = queries[i];
            stringToLower(temp);
            if (lower2Origin.find(temp) != lower2Origin.end()) {
                ans[i] = lower2Origin[temp];
                continue;
            }
            string2foolString(temp);
            if (vowel2Origin.find(temp) != vowel2Origin.end()) {
                ans[i] = vowel2Origin[temp];
            }

            #ifdef DEFF
            if (wordSet.count(queries[i]) > 0) {
                ans[i] = queries[i];
                continue;
            }
            string temp = queries[i];
            stringToLower(temp);
            if (lower2Origin.count(temp) > 0) {
                ans[i] = lower2Origin[temp];
                continue;
            }
            string2foolString(temp);
            if (vowel2Origin.count(temp) > 0) {
                ans[i] = vowel2Origin[temp];
            }
            #endif
            
        }
        return ans;
    }
};
// @lc code=end
