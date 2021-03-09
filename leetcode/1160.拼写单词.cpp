/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
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
    int countCharacters(vector<string>& words, string chars) {
        vector<int> hash(26);
        for (int i = 0; i < chars.size(); ++i) {
            hash[chars[i] - 'a']++;
        }
        int ans = 0;
        for (auto str : words) {
            auto temp = hash;
            bool ok = true;
            for (char c : str) {
                if (--temp[c - 'a'] < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += str.size();
            }
        }
        return ans;
    }
};
// @lc code=end

