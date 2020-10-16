/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
    /*
        1. i s的下标
        2. j j 的下标
    */
    struct regex {
        regex() {}

        /*

        */
        void matchHelper(char pre, int& i, int& j, const string& s,
                         const string& p) {
            j += 2;
            if (s[i] != pre) {
                return;
            }
            while (i < s.size() && s[i] == pre) {
                ++i;
            }
        }

        bool dfs(int i, int j, const string& s, const string& p) {
            if (s.size() == 0) {
                return true;
            }
            if (p.size() == 0) {
                return false;
            }
            int sSize = s.size();
            int pSize = p.size();
            while (i < sSize && j < pSize) {
                char cS = s[i];
                char pS = p[j];
                if (j + 1 < pSize && p[j + 1] == '*') {
                    if (pS == '.') {
                        // 最后的 .* 直接返回
                        if (j + 1 == pSize - 1) {
                            return true;
                        }
                        bool r = false;
                        for (int idx = i; idx < sSize; ++idx) {
                            r |= dfs(idx, j + 2, s, p);
                            if (r) {
                                return true;
                            }
                        }
                        return false;
                    }
                    matchHelper(pS, i, j, s, p);
                    continue;
                }
                // ps 前面没有字符串
                if (pS == '*') {
                    return false;
                }
                if (pS == cS || pS == '.') {
                    ++i;
                    ++j;
                } else if (pS != cS) {
                    return false;
                }
            }
            return i == sSize && j == pSize;
        }
    };

    bool isMatch(string s, string p) {
        regex r;
        return r.dfs(0, 0, s, p);
    }
};
// @lc code=end

struct tester {
    string s;
    string p;
    bool ret;
};

int main() {
    Solution so;
    vector<tester> te= {
        // {"aa", "a", false},
        // {"aa", "a*", true},
        // {"ab", ".*", true},
        // {"aab", "c*a*b", true},
        // {"mississippi", "mis*is*p*.", false},
        {"abbbb", ".*c", false},
    };

    for (int i = 0; i < te.size(); ++i) {
        if (te[i].ret != so.isMatch(te[i].s, te[i].p)) {
            cout << te[i].s << endl;
            cout << te[i].p << endl;
        }
    }
}
