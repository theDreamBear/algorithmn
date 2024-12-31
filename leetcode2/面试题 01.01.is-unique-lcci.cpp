/*
 * @lc app=leetcode.cn id=面试题 01.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 01.01] 判定字符是否唯一
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
    bool isUnique(string astr) {
        int cnt[300]{};
        for (auto ch: astr) {
            if (++cnt[ch] > 1) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

