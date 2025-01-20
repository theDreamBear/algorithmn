/*
 * @lc app=leetcode.cn id=1647 lang=cpp
 * @lcpr version=30204
 *
 * [1647] 字符频次唯一的最小删除次数
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minDeletions(string s) {
        int cnt[26]{};
        for (auto ch: s) cnt[ch - 'a']++;
        ranges::sort(cnt);
        int last = 0;
        for (auto v: cnt) {
            if (v) {
                last = v - 1;
                break;
            }
        }
        int pre = 0;
        for (auto v: cnt} {
            if (!v or) continue;
            if (v)
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "aaabbbcc"\n
// @lcpr case=end

// @lcpr case=start
// "ceabaacb"\n
// @lcpr case=end

 */

