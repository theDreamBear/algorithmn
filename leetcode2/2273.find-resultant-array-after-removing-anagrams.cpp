/*
 * @lc app=leetcode.cn id=2273 lang=cpp
 * @lcpr version=30204
 *
 * [2273] 移除字母异位词后的结果数组
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
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        auto isS = [](string a, string b)->bool {
            if (a.size() != b.size()) return false;
            ranges::sort(a);
            ranges::sort(b);
            return a == b;
        };
        for (int i = 0; i < words.size(); i++) {
            if (!ans.empty() and isS(ans.back(), words[i])) {
                continue;
            }
            ans.push_back(words[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abba","baba","bbaa","cd","cd"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","c","d","e"]\n
// @lcpr case=end

 */

