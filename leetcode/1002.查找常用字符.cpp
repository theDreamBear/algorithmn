/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> times(26, INT_MAX);

        for (auto& str : A) {
            vector<int> temp(26);
            for (auto c : str) {
                ++temp[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                times[i] = min(times[i], temp[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < times[i]; ++j) {
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }
};
// @lc code=end

