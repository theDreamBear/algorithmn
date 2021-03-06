/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
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
    vector<int> diStringMatch1(string S) {
        vector<int> ans(S.size() + 1);
        vector<pair<int, int>> pairs;
        pairs.push_back({0, 0});
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == 'I') {
                ans[i + 1] = ans[i] + 1;
            } else {
                ans[i + 1] = ans[i] - 1;
            }
            pairs.push_back({ans[i + 1], i + 1});
        }
        sort(pairs.begin(), pairs.end());
        for (int i = 0; i < pairs.size(); ++i) {
            ans[pairs[i].second] = i;
        }
        return ans;
    }

    vector<int> diStringMatch(string S) {
        vector<int> ans(S.size() + 1);
        int m = 0, n = S.size();
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == 'I') {
                ans[i] = m++;
            } else {
                ans[i] = n--;
            }
        }
        ans.back() = m;
        return ans;
    }
};
// @lc code=end

