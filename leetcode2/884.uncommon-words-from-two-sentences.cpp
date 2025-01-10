/*
 * @lc app=leetcode.cn id=884 lang=cpp
 * @lcpr version=30204
 *
 * [884] 两句话中的不常见单词
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        auto get = [&](string s) {
            auto p = strtok((char*)s.c_str(), " ");
            while (p) {
                freq[p]++;
                p = strtok(NULL, " ");
            }
        };
        get(s1), get(s2);
        vector<string> ans;
        for (auto& [k, v]: freq) {
            if (v == 1) ans.push_back(k);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "this apple is sweet"\n"this apple is sour"\n
// @lcpr case=end

// @lcpr case=start
// "apple apple"\n"banana"\n
// @lcpr case=end

 */

