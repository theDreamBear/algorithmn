/*
 * @lc app=leetcode.cn id=2029 lang=cpp
 * @lcpr version=30204
 *
 * [2029] 石子游戏 IX
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
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val: stones) {
            if (int type = val % 3; type == 0) {
                ++cnt0;
            }
            else if (type == 1) {
                ++cnt1;
            }
            else {
                ++cnt2;
            }
        }
        if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,2,4,3]\n
// @lcpr case=end

 */

