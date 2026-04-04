/*
 * @lc app=leetcode.cn id=318 lang=cpp
 * @lcpr version=30204
 *
 * [318] 最大单词长度乘积
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
    class Dec{
     public:
        long long code = 0;

        int len() {
            return code >> 26;
        }

        long long mask() {
            return code & ((1 << 26) - 1);
        }

        void set(const string& str) {
            long long sz = str.size();
            code = (sz << 26);
            for (auto ch: str) {
                code |= (1 << (ch - 'a'));
            }
        }
    };

    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<Dec> decs(words.size());
        for (int i = 0; i < words.size(); i++) {
            decs[i].set(words[i]);
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if (!(decs[i].mask() & decs[j].mask())) {
                    ans = max(ans, decs[i].len() * decs[j].len());
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abcw","baz","foo","bar","xtfn","abcdef"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","ab","abc","d","cd","bcd","abcd"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","aa","aaa","aaaa"]\n
// @lcpr case=end

 */

