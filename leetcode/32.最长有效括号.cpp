/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
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

    int validBracket(const string& s, int start) {
        if (start >= s.size()) {
            return -1;
        }
        stack<char> st;
        int i = start;
        for (; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return i + 1;
                } else {
                    st.pop();
                    if (st.empty()) {
                        return i + 1;
                    }
                }
            }
        }
        return -1;
    }

    int longestValidParentheses(string s) {
        if (s.size() <= 1) {
            return 0;
        }
        int mLen = 0;
#define one
#ifdef one
        /*
            压缩数组 + 剪枝 5% + 5% 勉强通过
        */
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                for (int j = i - 1; j >= 0; --j) {
                    if (s[j] == '(' && isValidBracket(s, j, i)) {
                        int len = i - j + 1;
                        if (j - 1 >= 0) {
                            dp[i] = dp[j - 1] + len;
                        } else {
                            dp[i] = len;
                        }
                        if (dp[i] > mLen) {
                            mLen = dp[i];
                        }
                        break;
                    }
                }
            }
        }
#endif  // one

#ifdef two
        set<string> sSet;
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

#ifdef three
        /*
            某些 case不能通过
        */
        int len = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == '(') {
                int pos = validBracket(s, i);
                if (pos == -1) {
                    ++i;
                    len = 0;
                } else {
                    len += (pos - i);
                    if (len > mLen) {
                        mLen = len;
                    }
                    i = pos;
                }
            } else {
                len = 0;
                ++i;
            }
        }
#endif  // three
        return mLen;
    }
};
