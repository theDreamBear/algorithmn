/*
 * @lc app=leetcode.cn id=LCR 034 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 034] 验证外星语词典
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
    bool isAlienSorted(vector<string>& words, string order) {
        int ct[26];
        for (int i = 0; i < order.size(); i++) {
            ct[order[i] - 'a'] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                int k = 0;
                for (; k < words[j].size() and k < words[i].size(); k++) {
                    if (ct[words[i][k] - 'a'] > ct[words[j][k] - 'a']) {
                        return false;
                    } else if (ct[words[i][k] - 'a'] < ct[words[j][k] - 'a']) {
                        break;
                    }
                }
                if (k < words[i].size() and k == words[j].size()) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"\n
// @lcpr case=end

// @lcpr case=start
// ["word","world","row"]\n"worldabcefghijkmnpqstuvxyz"\n
// @lcpr case=end

// @lcpr case=start
// ["apple","app"]\n"abcdefghijklmnopqrstuvwxyz"\n
// @lcpr case=end

 */

