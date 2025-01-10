/*
 * @lc app=leetcode.cn id=804 lang=cpp
 * @lcpr version=30204
 *
 * [804] 唯一摩尔斯密码词
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
    int uniqueMorseRepresentations(vector<string>& words) {
        string encode[26]{
            ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> uniq;
        for (auto& s: words) {
            string tmp;
            for (auto ch: s) {
                tmp += encode[ch - 'a'];
            }
            if (!uniq.contains(tmp)) uniq.insert(tmp);
        }
        return uniq.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["gin", "zen", "gig", "msg"]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

