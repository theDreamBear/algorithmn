/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
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
    int maxProduct(vector<string>& words) {
        vector<int> bf(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                bf[i] |= (0x1 <<(words[i][j] - 'a'));
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (((bf[i] & bf[j]) == 0) && (words[i].size() * words[j].size() > ans)) {
                    ans = words[i].size() * words[j].size();
                }
            }
        }
        return ans;
    }
};
// @lc code=end

