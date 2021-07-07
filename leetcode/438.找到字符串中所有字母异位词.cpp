/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ah(26);
        int ct = 0;
        for (auto c : p) {
            if (++ah[c - 'a'] == 1) {
                ++ct;
            }
        }
        vector<int> ans;
        vector<int> temp = ah;
        int left = ct;
        int i = 0;
        for (int j = i; j < s.size(); ++j) {
            // 不存在字符直接跳过
            if (ah[s[j] - 'a'] == 0) {
                i = j;
                ++i;
                temp = ah;
                left = ct;
                continue;
            }
            // 字符刚好用完
            if (--temp[s[j] - 'a'] == 0) {
                if (--left == 0) {
                    ans.emplace_back(i);
                    ++temp[s[i] - 'a'];
                    ++i;
                    left = 1;
                }
                continue;
            }
            // 超支了
            if (temp[s[j] - 'a'] < 0) {
                for (; i <= j;) {
                    if (++temp[s[i++] - 'a'] == 1) {
                        ++left;
                    } else if (temp[s[j] - 'a'] == 0) {
                        break;
                    }
                }
                continue;
            }
        }
        return ans;
    }
};
// @lc code=end

