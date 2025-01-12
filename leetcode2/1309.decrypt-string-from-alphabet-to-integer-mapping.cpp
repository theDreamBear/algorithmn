/*
 * @lc app=leetcode.cn id=1309 lang=cpp
 * @lcpr version=30204
 *
 * [1309] 解码字母到整数映射
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
    string freqAlphabets(string s) {
        string ans;
        auto get = [](string s) {
            return atoi(s.c_str()) + 'a' - 1;
        };
        for (int i = 0; i < s.size(); ) {
            if (i + 2 < s.size() and s[i + 2] == '#') {
                string tmp;
                tmp += s[i];
                tmp += s[i + 1];
                if (tmp <= "26") {
                    ans.push_back(get(tmp));
                    i += 3;
                    continue;
                }
            }
            ans.push_back(get(string(1, s[i++])));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "10#11#12"\n
// @lcpr case=end

// @lcpr case=start
// "1326#"\n
// @lcpr case=end

 */

