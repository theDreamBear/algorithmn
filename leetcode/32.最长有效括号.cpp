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

    int validBracket2(const string& s) {
        if (s.size() <= 1) {
            return 0;
        }
        stack<int> st;
        vector<pair<int, int>> saved;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    int l = st.top();
                    int r = i;
                    saved.push_back({l, r});
                    st.pop();
                }
            }
        }
        sort(saved.begin(), saved.end(), less<pair<int, int>>());
        int len = 0;
        int mLen = 0;
        int left = -1, right = -2;
        for (int i = 0; i < saved.size(); ++i) {
            if (left == -1) {
                left = saved[i].first;
                right = saved[i].second;
            } else {
                if (right + 1 == saved[i].first) {
                    right = saved[i].second;
                } else if (right + 1 < saved[i].first) {
                    len = right - left + 1;
                    if (len > mLen) {
                        mLen = len;
                    }
                    left = saved[i].first;
                    right = saved[i].second;
                    len = 0;
                }
            }
        }
        len = right - left + 1;
        if (len > mLen) {
            mLen = len;
        }
        return mLen;
    }

    int longestValidParentheses(string s) {
        if (s.size() <= 1) {
            return 0;
        }
        int mLen = 0;
#define four
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
        int cl = 0, rl = 0;
        int low = -1;
        int high = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++cl;
                if (low == -1) {
                    low = i;
                }
            } else {
                ++rl;
                high = i;
            }
        }
        if (cl * rl == 0) {
            return false;
        }

        int len = 0;
        for (int i = low; i <= high;) {
            if (s[i] == '(') {
                int pos = validBracket(s, i);
                if (pos < 0) {
                    i -= pos;
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

#ifdef four
        return validBracket2(s);
#endif  // four
        return mLen;
    }
};
// @lc code=end
int main() {
    string s = ")(((((()())()()))()(()))(";
    cout << Solution{}.longestValidParentheses(s);
}