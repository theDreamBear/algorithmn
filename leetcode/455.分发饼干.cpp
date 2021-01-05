/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                ++i;
                ++j;
                ++ans;
            } else {
                ++j;
            }
        }
        return ans;
    }
};
// @lc code=end

