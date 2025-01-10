/*
 * @lc app=leetcode.cn id=819 lang=cpp
 * @lcpr version=30204
 *
 * [819] 最常见的单词
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
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> freq;
        unordered_set<string> ban;
        for (auto& s: banned) {
            ban.insert(s);
        }
        string ans;
        int cnt = 0;
        for (int i = 0; i < paragraph.size();) {
            int start = i++;
            if (isalpha(paragraph[start])) {
                while (i < paragraph.size() and isalpha(paragraph[i])) i++;
                string tmp = paragraph.substr(start, i - start);
                for (auto& ch: tmp) {
                    ch = tolower(ch);
                }
                if (ban.contains(tmp)) continue;
                if (++freq[tmp] > cnt) {
                    ans = tmp;
                    cnt = freq[tmp];
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]\n
// @lcpr case=end

// @lcpr case=start
// "a."\n[]\n
// @lcpr case=end

 */

