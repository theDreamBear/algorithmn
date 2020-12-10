/*
 * @lc app=leetcode.cn id=966 lang=cpp
 *
 * [966] 元音拼写检查器
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
    string completeMatch(set<string> wordSet, const string& queryWord) {
        if (wordSet.find(queryWord) != wordSet.end()) {
            return queryWord;
        }
        return "";
    }


    void stringToLower(string& str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    string ignoreCaseMatch(map<string, string>& wordMap, string queryWord){
        stringToLower(queryWord);
        return wordMap[queryWord];
    }

    bool isVowel(char c) {
        switch(c) {
            case  'a':
            case  'e':
            case  'i':
            case  'o':
            case  'u':
                return true;
            default:
                return false;
        }
        return false;
    }

    /*
     所有元音都变成 "_"
    */
    void string2foolString(string& str) {
        for (auto& c : str) {
            if (isVowel(c)) {
                c = '_';
            }
        }
    }

    string vowelMatch(map<string, string>& wordMap, string queryWord){
        stringToLower(queryWord);
        string2foolString(queryWord);
        return wordMap[queryWord];
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> wordSet;
        for (auto& str : wordlist) {
            wordSet.insert(str);
        }
        map<string, string> lower2Origin;
        map<string, string> vowel2Origin;
        for (int i = int(wordlist.size()) - 1; i >= 0; --i) {
            string temp = wordlist[i];
            stringToLower(temp);
            lower2Origin[temp] = wordlist[i];
            string2foolString(temp);
            vowel2Origin[temp] = wordlist[i];
        }

        vector<string> ans(queries.size(), "");
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = completeMatch(wordSet, queries[i]);
            if (ans[i] == "") {
                ans[i] = ignoreCaseMatch(lower2Origin, queries[i]);
            }
            if (ans[i] == "") {
                ans[i] = vowelMatch(vowel2Origin, queries[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"keti","keet","keto"};
    auto x = Solution{}.spellchecker(wordlist, queries);
    for (auto& str : x) {
        cout << str << "\t";
    }
    cout << endl;
}
