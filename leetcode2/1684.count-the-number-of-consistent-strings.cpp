/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 * @lcpr version=30204
 *
 * [1684] 统计一致字符串的数目
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
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        int act[26]{};
        for (auto ch: allowed) {
            act[ch - 'a']++;
        }
        for (auto& word: words) {
            bool ok = true;
            for (auto ch: word) {
                if (!act[ch - 'a']) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ab"\n["ad","bd","aaab","baa","badab"]\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n["a","b","c","ab","ac","bc","abc"]\n
// @lcpr case=end

// @lcpr case=start
// "cad"\n["cc","acd","b","ba","bac","bad","ac","d"]\n
// @lcpr case=end

 */

