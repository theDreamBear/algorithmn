/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
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

    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        // 预处理
        unordered_set<char> s1;
        unordered_set<char> s2;
        unordered_set<char> s3;

        string a1 = "qwertyuiop";
        string a2 = "asdfghjkl";
        string a3 = "zxcvbnm";
        for (auto x : a1) {
            s1.insert(x);
            s1.insert(toupper(x));
        }

        for (auto x : a2) {
            s2.insert(x);
            s2.insert(toupper(x));
        }

        for (auto x : a3) {
            s3.insert(x);
            s3.insert(toupper(x));
        }

        const unordered_set<char>* sptr = NULL;
        for (auto& s : words) {
            if (s1.count(s[0]) != 0) {
                sptr = &s1;
            } else if (s2.count(s[0]) != 0) {
                sptr = &s2;
            } else {
                sptr = &s3;
            }
            bool found = true;
            int i = 1;
            for (; i < s.size(); ++i) {
                if (sptr->count(s[i]) == 0) {
                    found = false;
                    break;
                }
            }
            if (i == s.size()) {
                ans.push_back(s);
            }
        }
        return ans;
    }

};
// @lc code=end

