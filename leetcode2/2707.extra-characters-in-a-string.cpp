/*
 * @lc app=leetcode.cn id=2707 lang=cpp
 * @lcpr version=30204
 *
 * [2707] 字符串中的额外字符
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
    int minExtraChar(string s, vector<string>& dictionary) {
        // 选择
        //
        // 不选
        int n = s.size();
        vector<int> f(n + 1);
        int max_len = ranges::max(dictionary, {}, &string::size).size();
        unordered_set<string> dic(dictionary.begin(), dictionary.end());
        for (int i = 0; i < s.size(); i++) {
            // 直接+1
            f[i + 1] = f[i] + 1;
            for (int j = i; j >= max(0, i - max_len + 1); j--) {
                if (dic.contains(s.substr(j, i - j + 1))) {
                    f[i + 1] = min(f[i + 1], f[j]);
                }
            }
        }
        return f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetscode"\n["leet","code","leetcode"]\n
// @lcpr case=end

// @lcpr case=start
// "sayhelloworld"\n["hello","world"]\n
// @lcpr case=end

 */

