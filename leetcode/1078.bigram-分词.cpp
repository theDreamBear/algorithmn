/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
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
    vector<string> findOcurrences(string text, string first, string second) {
        string prefix = first + " " + second + " ";
        vector<string> ans;
        const char* pos = strstr(text.c_str(), prefix.c_str());
        while (pos != NULL) {
            if (pos == text.c_str() || *(pos - 1) == ' ') {
                pos += prefix.size();
                const char* p = pos;
                int ct = 0;
                while (*p != '\0' && *p != ' ') {
                    ++p;
                    ++ct;
                }
                if (ct > 0) {
                    ans.emplace_back(pos, ct);
                }
            } else {
                pos += prefix.size();
            }
            pos = strstr(pos, prefix.c_str());
        }
        return ans;
    }
};
// @lc code=end

