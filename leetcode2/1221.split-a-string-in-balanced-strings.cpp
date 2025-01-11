/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 * @lcpr version=30204
 *
 * [1221] 分割平衡字符串
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
    int balancedStringSplit(string s) {
        int cnt = 0;
        int ans = 0;
        for (auto ch: s) {
            if (ch == 'L') cnt++;
            else cnt--;
            if (cnt == 0) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "RLRRLLRLRL"\n
// @lcpr case=end

// @lcpr case=start
// "RLRRRLLRLL"\n
// @lcpr case=end

// @lcpr case=start
// "LLLLRRRR"\n
// @lcpr case=end

 */

