/*
 * @lc app=leetcode.cn id=1935 lang=cpp
 * @lcpr version=30204
 *
 * [1935] 可以输入的最大单词数
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
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string s;
        unordered_set<char> broken;
        for (auto ch: brokenLetters) broken.insert(ch);
        int ans = 0;
        while (ss >> s) {
            bool ok = true;
            for (auto ch: s) {
                if (broken.contains(ch)) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "hello world"\n"ad"\n
// @lcpr case=end

// @lcpr case=start
// "leet code"\n"lt"\n
// @lcpr case=end

// @lcpr case=start
// "leet code"\n"e"\n
// @lcpr case=end

 */

