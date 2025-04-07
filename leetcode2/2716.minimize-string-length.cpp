/*
 * @lc app=leetcode.cn id=2716 lang=cpp
 * @lcpr version=30204
 *
 * [2716] 最小化字符串长度
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
    int minimizedStringLength(string s) {
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        return s.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aaabc"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

// @lcpr case=start
// "dddaaa"\n
// @lcpr case=end

 */

