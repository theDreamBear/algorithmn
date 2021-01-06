/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
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
    string licenseKeyFormatting(string S, int K) {
        string ans;
        int sz = 0;
        for (int i = S.size() - 1; i >= 0; --i) {
            if (S[i] != '-') {
                char c = S[i];
                if (islower(c)) {
                    c = toupper(c);
                }
                if (sz < K) {
                    ans.push_back(c);
                    ++sz;
                    if (sz == K) {
                        ans.push_back('-');
                        sz = 0;
                    }
                }
            }
        }
        if (ans.back() == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

