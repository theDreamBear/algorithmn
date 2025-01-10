/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 * @lcpr version=30204
 *
 * [1160] 拼写单词
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
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        int cnt[26]{};
        for (auto ch: chars) cnt[ch - 'a']++;
        for (auto& word: words) {
            int ct[26]{};
            for (auto ch: word) ct[ch - 'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (ct[i] > cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += word.size();
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["cat","bt","hat","tree"]\n"atach"\n
// @lcpr case=end

// @lcpr case=start
// ["hello","world","leetcode"]\n"welldonehoneyr"\n
// @lcpr case=end

 */

