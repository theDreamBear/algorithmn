/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
     struct regex {
        vector<vector<int>> dp;
        regex() {}

        /*

        */
        bool isMinuscule(char c) { return c >= 'a' && c <= 'z'; }

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
                if (p[j] == '?' || s[i] == p[j]) {
                    ++i;
                    ++j;
                    continue;
                } 
                if (isMinuscule(p[j]) && s[i] != p[j]) {
                    return false;
                }
                while (j < p.size() && p[j] == '*') {
                    ++j;
                }
                bool r = false;
                for (int idx = i; idx <= s.size(); ++idx) {
                    r |= dfsNew2(idx, j, s, p);
                    dp[idx][j] = r;
                    if (r) {
                        break; 
                    }
                }
                return dp[i][j] = r;
            }
            while(j < p.size() && p[j] == '*') {
                ++j;
            }
            return dp[i][j] = i >= s.size() && j >= p.size();
        }
    };
    /*
    暴力搜索超时
    */
    bool isMatch(string s, string p) {
        regex r;
        r.dp = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return r.dfsNew2(0, 0, s, p);
    }
};
// @lc code=end

