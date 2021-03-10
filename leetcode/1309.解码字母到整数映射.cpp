/*
 * @lc app=leetcode.cn id=1309 lang=cpp
 *
 * [1309] 解码字母到整数映射
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
class Solution {
public:
    string freqAlphabets1(string s) {
        string ans;
        for (int i = s.size() - 1; i >= 0; ) {
            if (s[i] != '#') {
                ans.push_back(s[i] - '0' + 'a' - 1);
                --i;
            } else {
                int val = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                ans.push_back(val + 'a' - 1);
                i -= 3;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string freqAlphabets2(string s) {
        string ans;
        for (int i = 0; i < s.size(); ) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                int val = (s[i] - '0') * 10 + s[i + 1] - '0';
                ans.push_back(val + 'a' - 1);
                i += 3;
            } else {
                ans.push_back(s[i] - '0' + 'a' - 1);
                ++i;
            }
        }
        return move(ans);
    }

    string freqAlphabets(string s) {
        int j = 0;
        for (int i = 0; i < s.size(); ) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                int val = (s[i] - '0') * 10 + s[i + 1] - '0';
                s[j++] = val + 'a' - 1;
                i += 3;
            } else {
                s[j++] = s[i] - '0' + 'a' - 1;
                ++i;
            }
        }
        s.resize(j);
        return move(s);
    }
};
// @lc code=end

