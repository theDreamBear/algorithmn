/*
 * @lc app=leetcode.cn id=LCR 005 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 005] 最大单词长度乘积
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
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<int> sign(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                sign[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((sign[i] & sign[j]) == 0) {
                    ans = max((int)words[i].size() * (int)words[j].size(), ans);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abcw","baz","foo","bar","fxyz","abcdef"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","ab","abc","d","cd","bcd","abcd"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","aa","aaa","aaaa"]\n
// @lcpr case=end

 */

