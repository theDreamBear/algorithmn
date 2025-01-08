/*
 * @lc app=leetcode.cn id=3019 lang=cpp
 * @lcpr version=30204
 *
 * [3019] 按键变更的次数
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
    int countKeyChanges(string s) {
        int ans = -1;
        char pre = '1';
        for (auto ch: s) {
            if (tolower(ch) != pre) {
                pre = tolower(ch);
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aAbBcC"\n
// @lcpr case=end

// @lcpr case=start
// "AaAaAaaA"\n
// @lcpr case=end

 */

