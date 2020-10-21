/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <iostream>
#include <set>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
 public:
    bool isValidBracket(const string& s, int low, int high) {
        if (low >= high) {
            return false;
        }
        stack<char> st;
        if (s[low] == ')') {
            return false;
        }
        for (int i = low; i <= high; ++i) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            }
        }
        return st.size() == 0;
    }

    bool isValidBracketString(const string& s) {
        int low = 0, high = s.size() - 1;
        if (low >= high) {
            return false;
        }
        stack<char> st;
        if (s[low] == ')') {
            return false;
        }
        for (int i = low; i <= high; ++i) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            }
        }
        return st.size() == 0;
    }

    int longestValidParentheses(string s) {
        if (s.size() <= 1) {
            return 0;
        }
        int mLen = 0;
        set<string> sSet;
#define one
#ifdef one
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (isValidBracket(s, j, i) && i - j + 1 > mLen) {
                    cout << j << " " << i << endl;
                    mLen = i - j + 1;
                    ++j;
                }
            }
        }
#endif  // one

#ifdef two
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            if (s[j] == '(') {
                sSet.insert(s.substr(j, i - j + 1));
            }
        }
    }
    for (const string& str : sSet) {
        if (isValidBracketString(str) && mLen < str.size()) {
            mLen = str.size();
        }
    }
#endif  // two
    return mLen;
    }
};
