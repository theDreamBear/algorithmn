/*
 * @lc app=leetcode.cn id=2559 lang=cpp
 * @lcpr version=30204
 *
 * [2559] 统计范围内的元音字符串数
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n + 1);
        string vowels = "aeiou";
        auto isVowel = [&](char ch) {
            return vowels.find(ch) != string::npos;
        };
        for (int i = 0; i < words.size(); i++) {
            pre[i + 1] = pre[i] + (isVowel(words[i][0]) and isVowel(words[i][words[i].size() - 1]));
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int left = queries[i][0], right = queries[i][1];
            ans[i] = pre[right + 1] - pre[left];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["aba","bcb","ece","aa","e"]\n[[0,2],[1,4],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// ["a","e","i"]\n[[0,2],[0,1],[2,2]]\n
// @lcpr case=end

 */

