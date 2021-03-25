/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <iostream>
#include <string>
#include <vector>
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

using namespace std;
// @lc code=start
class Solution {
 public:
    /*
        1. i s的下标
        2. j j 的下标
    */
    struct regex {
        vector<vector<int>> dp;
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
            if (s.size() == 0 && p.size() == 0) {
                return true;
            }
            if (p.size() == 0) {
                cout << "i: " << i << " j: " << j << endl;
                return false;
            }

            if (i >= s.size() && j >= p.size()) {
                return true;
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
                        // cout << "i: " << i << " j: " << j << endl;
                        // return false;
                    }
                    // dfs
                    if (cS != pS) {
                        j += 2;
                    } else {
                        bool r = false;
                        j += 2;
                        for (; i < sSize;) {
                            if (s[i] == pS) {
                                r |= dfs(i, j, s, p);
                                if (r) {
                                    return true;
                                }
                                ++i;
                            } else {
                                break;
                            }
                        }
                    }
                    continue;
                }
                // ps 前面没有字符串
                // if (pS == '*') {
                //     return false;
                // }
                if (pS == cS || pS == '.') {
                    ++i;
                    ++j;
                } else if (pS != cS) {
                    cout << "i: " << i << " j: " << j << endl;
                    return false;
                }
            }
            if (i < sSize) {
                cout << "i: " << i << " j: " << j << endl;
                return false;
            }
            if (j >= pSize) {
                return true;
            }
            if (p[j + 1] == '*') {
                j += 2;
                return dfs(i, j, s, p);
            }
            cout << "i: " << i << " j: " << j << endl;
            return false;
        }

        bool isMinuscule(char c) { return c >= 'a' && c <= 'z'; }

        bool dfsNew(char pre, int i, int j, const string& s, const string& p) {
            // pre 非空
            // if (pre != '\0' && s[i] != pre) {
            //     return false;
            // }
            int sSize = s.size();
            int pSize = p.size();
            while (i < sSize && j < pSize) {
                if (j + 1 < pSize && p[j + 1] == '*') {
                    char pc = '\0';
                    if (isMinuscule(p[j])) {
                        pc = p[j];
                    }
                    bool r = false;
                    int last = sSize;
                    if (pc != '\0') {
                        last = i;
                        while (last < sSize && s[last] == pc) {
                            ++last;
                        }
                    }
                    j += 2;
                    int idx = i;
                    while (idx <= last) {
                        r |= dfsNew(pc, idx, j, s, p);
                        if (r) {
                            // cout << idx << " " << j << endl;
                            return true;
                        }
                        ++idx;
                    }
                    continue;
                }
                if (p[j] == '.' || s[i] == p[j]) {
                    ++j;
                    ++i;
                } else {
                    return false;
                }
            }
            if (i >= s.size()) {
                // 都到末尾了
                if (j >= p.size()) {
                    return true;
                }
                // s 遍历结束， p 还未结束， 需要检查末尾是否可以排空 a*, b*
                // 之类的
                while (j + 1 < p.size()) {
                    if ((p[j] == '.' || isMinuscule(p[j])) && p[j + 1] == '*') {
                        j += 2;
                    } else {
                        break;
                    }
                }
                if (j >= p.size()) {
                    return true;
                }
                return false;
            }
            // if (i < sSize && pre != '\0') {
            //     while (s[i] == pre) {
            //         ++i;
            //     }
            // }
            return i >= sSize && j >= pSize;
        }

        /*
      true  i >= s.size() && j >= p.size()
      .*
      a*

  */

        bool dfsNew2(int i, int j, const string& s, const string& p) {
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            while (i < s.size() && j < p.size()) {
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    char pre = p[j];
                    // j 的值改变了所以需要保存下来
                    j += 2;
                    if (isMinuscule(pre) && s[i] != pre) {
                        continue;
                    }
                    bool r = false;
                    int last = i;
                    if (pre == '.') {
                        last = s.size();
                    } else {
                        while (last < s.size() && s[last] == pre) {
                            ++last;
                        }
                    }
                    for (int idx = i; idx <= last; ++idx) {
                        r |= dfsNew2(idx, j, s, p);
                        dp[idx][j] = r;
                        if (r) {
                            break;
                        }
                    }
                    return  dp[i][j] =  r;
                }
                if (p[j] == '.' || s[i] == p[j]) {
                    ++i;
                    ++j;
                } else {
                    return false;
                }
            }
            if (i >= s.size()) {
                if (j >= p.size()) {
                    return true;
                }
                while (j + 1 < p.size()) {
                    if (p[j + 1] == '*') {
                        j += 2;
                    } else {
                        break;
                    }
                }
            }
            return dp[i][j] = i >= s.size() && j >= p.size();
        }
    };
    bool isMatch2(string s, string p) {
        regex r;
        // dfsNew
        r.dp = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        //return r.dfsNew2('\0', 0, 0, s, p);

        return r.dfsNew2(0, 0, s, p);
        // if (s.size() == p.size() == 0) {
        //     return true;
        // }
        // if (p.size() == 0) {
        //     return false;
        // }
        // if (s.size() == 0) {
        //     int k = 1;
        //     while (k < p.size() && p[k] == '*') {
        //         k += 2;
        //     }
        //     return k > p.size();
        // }
        // int row = s.size();
        // int col = p.size();
        // vector<vector<bool>> dp(row, vector<bool>(col, false));
        // if (p[col -1] >= 'a' && p[col - 1] <= 'z' && p[col - 1] != s[row]) {
        //     return false;
        // }
        // dp[row - 1][col - 1] = true;

        // for (int i = row - 1; i >= 0; --i) {
        //     for (int j = col - 1; j >= 0; --j) {

        //     }
        // }
        // return true;
    }

    unordered_set<string> ok;

    bool dfs(int i, int j, string& s, string& p) {
        // string key = to_string(i) + "_" + to_string(j);
        // if (ok.count(key) > 0) {
        //     return false;
        // }
        if (i >= s.size() || j >= p.size()) {
            while (j < p.size() - 1 && p[j + 1] == '*') {
                j += 2;
            }
            if (j == p.size() && i == s.size()) {
                return true;
            }
            //ok.insert(key);
            return false;
        }
        if (p[j] == '*') {
            //ok.insert(key);
            return false;
        }
        if (j + 1 < p.size()) {
            if (p[j] == s[i]) {
                if (p[j + 1] != '*') {
                    return dfs(i + 1, j + 1, s, p);
                } else {
                    for (int k = i; k <= s.size(); ++k) {
                        if (dfs(k, j + 2, s, p)) {
                            return true;
                        }
                        if (k < s.size() && s[k] != p[j]) {
                            break;
                        }
                    }
                }
            }
            if (p[j] != s[i]) {
                if (p[j] == '.') {
                    if (p[j + 1] != '*') {
                        return dfs(i + 1, j + 1, s, p);
                    }
                    for (int k = i; k <= s.size(); ++k) {
                        if (dfs(k, j + 2, s, p)) {
                            return true;
                        }
                    }
                } else if (p[j + 1] == '*') {
                    return dfs(i, j + 2, s, p);
                }
                //ok.insert(key);
                return false;
            }
        }
        if (p[j] == s[i] || p[j] == '.') {
            return dfs(i + 1, j + 1, s, p);
        }
        //ok.insert(key);
        return false;
    }

    bool isMatch(string s, string p) {
        return dfs(0, 0, s, p);
    }
};
// @lc code=end

struct tester {
    string s;
    string p;
    bool ret;
};

int main(int argc, char* argv[]) {
    Solution so;
    vector<tester> te = {
        // {"aa", "a", false},
        // {"aa", "a*", true},
        // {"ab", ".*", true},
        // {"aab", "c*a*b", true},
        // {"mississippi", "mis*is*p*.", false},
        // {"abbbb", ".*c", false},
        // {"aaa", "c*a", false},
        // {"aa", "a*", true},
        {"aaa", "ab*a", true},
        // {"a", "ab*a", false},
        // {"", ".", false},
        //{"abcaaaaaaabaabcabac", ".*ab.a.*a*a*.*b*b*", true},
        // {"bb", ".baa", false},
        // {"", "c*c*", true},
        // {"abbbb", "a*.*b*.*a*aa*a*", false},
    };

    for (int i = 0; i < te.size(); ++i) {
        if (te[i].ret != so.isMatch(te[i].s, te[i].p)) {
            cout << te[i].s << " " << te[i].p << endl;
        }
    }
    // while (true) {
    //     string s, p;
    //     cout << "please input s and p: ";
    //     cin >> s >> p;
    //     cout << Solution{}.isMatch(s, p) << endl;
    // }
}
